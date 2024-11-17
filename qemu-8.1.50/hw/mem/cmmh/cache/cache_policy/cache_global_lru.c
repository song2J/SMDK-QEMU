#include "../cache.h"
#include "qemu/osdep.h"
#include "qemu/uuid.h"
#include "qemu/units.h"

typedef struct GlobalLRUCache
{
    CacheLine **heads;
    CacheLine *lru_head;
    CacheLine *lru_tail;
} GlobalLRUCache;

typedef struct PolicySpecificData
{
    CacheLine* next;
    CacheLine* prev;

    CacheLine* lru_next;
    CacheLine* lru_prev;
} PolicySpecificData;

static inline uint64_t get_cache_offset(CMMHCache* cc, uint64_t dpa)
{
    return dpa % (1 << cc->line_bits);
}

static inline uint64_t get_cache_tag(CMMHCache* cc, uint64_t dpa)
{
    return (dpa >> (cc->line_bits + cc->index_bits));// & ((1 << (cc->tag_bits)) - 1);
}

static inline uint64_t get_cache_idx(CMMHCache* cc, uint64_t dpa)
{
    return (dpa >> (cc->line_bits)) % (1 << (cc->index_bits)); 
}

static inline uint64_t get_dpa(CMMHCache *cc, uint64_t tag, uint64_t idx, uint64_t off)
{
    return (tag << (cc->index_bits + cc->line_bits)) + (idx << cc->line_bits) + off;
}

static inline CacheLine *get_next_line (CacheLine* curr)
{
    return ((PolicySpecificData*)(curr->policy_specific_data))->next;
}

static inline void set_next_line (CacheLine* curr, CacheLine* next)
{
    ((PolicySpecificData*)(curr->policy_specific_data))->next = next;
}

static inline CacheLine *get_prev_line (CacheLine* curr)
{
    return ((PolicySpecificData*)(curr->policy_specific_data))->prev;
}

static inline void set_prev_line (CacheLine* curr, CacheLine* prev)
{
    ((PolicySpecificData*)(curr->policy_specific_data))->prev = prev;
}

static inline CacheLine *get_next_lru_line (CacheLine* curr)
{
    return ((PolicySpecificData*)(curr->policy_specific_data))->lru_next;
}

static inline void set_next_lru_line (CacheLine* curr, CacheLine* next)
{
    ((PolicySpecificData*)(curr->policy_specific_data))->lru_next = next;
}

static inline CacheLine *get_prev_lru_line (CacheLine* curr)
{
    return ((PolicySpecificData*)(curr->policy_specific_data))->lru_prev;
}

static inline void set_prev_lru_line (CacheLine* curr, CacheLine* prev)
{
    ((PolicySpecificData*)(curr->policy_specific_data))->lru_prev = prev;
}

static inline CacheLine *allocate_line(void)
{
    CacheLine *ret = g_malloc0(sizeof(CacheLine));
    ret->policy_specific_data = g_malloc0(sizeof(PolicySpecificData));
    return ret;
}

static void cache_promote_line(CMMHCache *cc, uint64_t idx, CacheLine *curr)
{
    GlobalLRUCache *table = cc->table;
    CacheLine** heads = table->heads;
    CacheLine** lru_head_p = &(table->lru_head);
    CacheLine** lru_tail_p = &(table->lru_tail);

    /* Phase1: evict the line from the previous list */
    CacheLine *prev = get_prev_line(curr);
    CacheLine *next = get_next_line(curr);
    uint64_t prev_idx = get_cache_idx(cc, curr->dpa);

    if(prev)
        set_next_line(prev, next);
    if(next)
        set_prev_line(next, prev);
    if(heads[prev_idx] == curr)
        heads[prev_idx] = get_next_line(curr);

    /* Phase2: Insert the line to the Current list */
    if(heads[idx])
        set_prev_line(heads[idx], curr);
    set_next_line(curr, heads[idx]);
    set_prev_line(curr, NULL);
    heads[idx] = curr;

    /* Phase3: Update lru list(if curr == lru_head, do nothing) */
    if(curr == *lru_head_p)
        return;

    CacheLine *lru_prev = get_prev_lru_line(curr);
    CacheLine *lru_next = get_next_lru_line(curr);

    if(*lru_tail_p == curr)
        *lru_tail_p = get_prev_lru_line(curr);

    if(lru_prev)
        set_next_lru_line(lru_prev, lru_next);
    
    if(lru_next)
        set_prev_lru_line(lru_next, lru_prev);

    set_next_lru_line(curr, *lru_head_p);
    set_prev_lru_line(*lru_head_p, curr);
    set_prev_lru_line(curr, NULL);
    *lru_head_p = curr;
}

/*
    access to the proposed cache entry
    if exist: return the pointer of the entry, victim = UINT64_MAX
    else:   return the pointer of the victim entry(LRU rule), victim = (dpa of the entry)
*/

static CacheLine* cache_access(CMMHCache *cc, uint64_t dpa, uint64_t *victim)
{
   // cmmh_cache_log("%s, CMMH Cache access [Entered] at [%x]!\n, OFFSET=[%d]", "CACHE", dpa, get_cache_offset(cc, dpa));
    dpa -= get_cache_offset(cc, dpa);
    uint64_t tag = get_cache_tag(cc, dpa);
    uint64_t idx = get_cache_idx(cc, dpa);
    
    GlobalLRUCache *table = cc->table;
    CacheLine** heads = table->heads;

    CacheLine *curr = heads[idx];
    while(curr) {
        if(curr->valid && get_cache_tag(cc, curr->dpa) == tag) {
            cache_promote_line(cc, idx, curr);
            cc->cache_hit ++;
            *victim = UINT64_MAX;
    //        cmmh_cache_log("%s, HIT cmmh cache access [Returned] at [%x]! tag: %x index: %x\n", "cache", dpa, tag, idx);
            return curr;
        }
        curr = get_next_line(curr);
    }

    /* CACHE MISS */
    cc->cache_miss++;
    *victim = table->lru_tail->dpa;
    //cmmh_cache_log("%s, MISS victim: %x cmmh cache access [Returned] at [%x]! tag: %x index: %x\n", "cache", *victim, dpa, tag, idx);
    return table->lru_tail;
}

/*
    Modify the given entry; set dirty flag
*/

static void cache_modify(CMMHCache* cc, CacheLine* cn)
{
    //cmmh_cache_log("%s, CMMH Cache modify [Entered]!\n", "CACHE");
    cn->dirty = true;
}

/*
    Fill the cache with the given dpa
    Promote the node(LRU rule)
    set valid, unset dirty
    set tag corr.to given dpa
*/

static void cache_fill(CMMHCache* cc, CacheLine* cn, uint64_t dpa)
{
    //cmmh_cache_log("%s, CMMH Cache fill [Entered] at [%x]!\n", "CACHE", dpa);
    uint64_t idx = get_cache_idx(cc, dpa);

    cache_promote_line(cc, idx, cn);
    cn->valid = true;
    cn->dirty = false;
    cn->dpa = dpa - get_cache_offset(cc, dpa);
}

static CacheLine *cache_advance_valid_line(CMMHCache *cc, CacheLine *cn)
{
    GlobalLRUCache *table = cc->table;
    CacheLine *ret = get_next_lru_line(cn);
    while(ret && !ret->valid)
        ret = get_next_lru_line(ret);
    return ret;
}

static CacheLine *cache_get_valid_head_line(CMMHCache *cc)
{
    GlobalLRUCache *table = cc->table;
    CacheLine *ret = table->lru_head;
    if(ret->valid == false)
        ret = cache_advance_valid_line(cc, ret);
    return ret;
}


void cmmh_cache_global_lru_init(CMMHCache *cc)
{
    //cmmh_cache_log("%s, CMMH Cache initialization [Entered]!\n", "CACHYEE");

    int index_bits = cc->index_bits;
    int num_tag = cc->num_tag;
    /* Currently single NAND Flash page size */
    cc->table = g_malloc0(sizeof(GlobalLRUCache));

    ((GlobalLRUCache*)cc->table)->heads = g_malloc0(sizeof(CacheLine*) * (1 << index_bits));
    ((GlobalLRUCache*)cc->table)->lru_head = NULL;
    ((GlobalLRUCache*)cc->table)->lru_tail = NULL;

    CacheLine** heads = ((GlobalLRUCache*)cc->table)->heads;
    CacheLine** lru_head_p = &(((GlobalLRUCache*)cc->table)->lru_head);
    CacheLine** lru_tail_p = &(((GlobalLRUCache*)cc->table)->lru_tail);

    for(int i = 0; i < (1 << index_bits); i++) {
        heads[i] = NULL;
        for(int j = 0; j < num_tag; j++) {
            CacheLine* curr = allocate_line();
            curr->dirty = false;
            curr->valid = false;
            curr->dpa = get_dpa(cc, 0, i, 0);

            if(heads[i] != NULL)
                set_prev_line(heads[i], curr);
            set_next_line(curr, heads[i]);
            set_prev_line(curr, NULL);
            heads[i] = curr;

            if(*lru_head_p != NULL)
                set_prev_lru_line(*lru_head_p, curr);
            set_next_lru_line(curr, *lru_head_p);
            set_prev_lru_line(curr, NULL);
            *lru_head_p = curr;
            if(*lru_tail_p == NULL)
                *lru_tail_p = curr;
        }
    }
    
    cc->access = cache_access;
    cc->modify = cache_modify;
    cc->fill = cache_fill;
    cc->get_valid_head_line = cache_get_valid_head_line;
    cc->advance_valid_line = cache_advance_valid_line;

    /* STATUS INIT */
    cc->cache_hit = 0;
    cc->cache_miss = 0;
    //cmmh_cache_log("%s, CMMH Cache initialization [FINISHED]!\n", "CACHYEE");
}