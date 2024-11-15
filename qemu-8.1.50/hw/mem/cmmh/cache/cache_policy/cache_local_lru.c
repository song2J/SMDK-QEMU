#include "../cache.h"
#include "qemu/osdep.h"
#include "qemu/uuid.h"
#include "qemu/units.h"

typedef struct PolicySpecificData
{
    CacheLine* next;
    CacheLine* prev;
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

static inline CacheLine *allocate_line(void)
{
    CacheLine *ret = g_malloc0(sizeof(CacheLine));
    ret->policy_specific_data = g_malloc0(sizeof(PolicySpecificData));
    return ret;
}

static void cache_promote_line(CMMHCache *cc, uint64_t idx, CacheLine *curr)
{
    CacheLine** table = (CacheLine**)cc->table;
    assert(idx == get_cache_idx(cc, curr->dpa));
    if(table[idx] == curr)
        return;

    CacheLine *prev = get_prev_line(curr);
    CacheLine *next = get_next_line(curr);

    if(prev)
        set_next_line(prev, next);
    
    if(next)
        set_prev_line(next, prev);

    set_next_line(curr, table[idx]);
    set_prev_line(table[idx], curr);
    set_prev_line(curr, NULL);
    table[idx] = curr;
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
    
    CacheLine **table = (CacheLine**)cc->table;

    CacheLine *curr = table[idx];
    CacheLine *bef;
    while(curr) {
        if(curr->valid && get_cache_tag(cc, curr->dpa) == tag) {
            cache_promote_line(cc, idx, curr);
            cc->cache_hit ++;
            *victim = UINT64_MAX;
    //        cmmh_cache_log("%s, HIT cmmh cache access [Returned] at [%x]! tag: %x index: %x\n", "cache", dpa, tag, idx);
            return curr;
        }
        bef = curr;
        curr = get_next_line(curr);
    }

    /* CACHE MISS */
    cc->cache_miss++;
    *victim = bef->dpa;
    //cmmh_cache_log("%s, MISS victim: %x cmmh cache access [Returned] at [%x]! tag: %x index: %x\n", "cache", *victim, dpa, tag, idx);
    return bef;
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
    CacheLine** table = (CacheLine**)cc->table;
    CacheLine *ret = get_next_line(cn);
    while(ret == NULL || !ret->valid) {
        if(get_next_line(ret)) { 
            ret = get_next_line(ret);
        } else {
            int next_idx = get_cache_idx(cc, cn->dpa) + 1;
            if(next_idx == (1 << (cc->index_bits)))
                return NULL;
            ret = table[next_idx];
        }
    }
    return ret;
}

static CacheLine *cache_get_valid_head_line(CMMHCache *cc)
{
    CacheLine **table = (CacheLine**)cc->table;
    CacheLine *ret = table[0];
    if(ret->valid == false)
        ret = cache_advance_valid_line(cc, ret);
    return ret;
}


void cmmh_cache_local_lru_init(CMMHCache *cc)
{
    //cmmh_cache_log("%s, CMMH Cache initialization [Entered]!\n", "CACHYEE");

    int index_bits = cc->index_bits;
    int num_tag = cc->num_tag;
    /* Currently single NAND Flash page size */
    cc->table = g_malloc0(sizeof(CacheLine*) * (1 << index_bits));
    CacheLine** table = (CacheLine**)cc->table;

    for(int i = 0; i < (1 << index_bits); i++) {
        table[i] = NULL;
        for(int j = 0; j < num_tag; j++) {
            CacheLine* curr = allocate_line();
            curr->dirty = false;
            curr->valid = false;
            curr->dpa = get_dpa(cc, 0, i, 0);
            if(table[i] != NULL)
                set_prev_line(table[i], curr);
            set_next_line(curr, table[i]);
            set_prev_line(curr, NULL);
            table[i] = curr;
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