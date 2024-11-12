#include "cache.h"
#include "qemu/osdep.h"
#include "qemu/uuid.h"
#include "qemu/units.h"

static inline uint64_t getCacheOffset(CMMHCache* cc, uint64_t dpa)
{
    return (dpa & ((1 << cc->line_bits) - 1));
}

static inline uint64_t getCacheTag(CMMHCache* cc, uint64_t dpa)
{
    return (dpa >> (cc->line_bits + cc->index_bits));// & ((1 << (cc->tag_bits)) - 1);
}

static inline uint64_t getCacheIdx(CMMHCache* cc, uint64_t dpa)
{
    return (dpa >> (cc->line_bits)) & ((1 << (cc->index_bits)) - 1);
}

static inline uint64_t get_dpa(CMMHCache *cc, uint64_t tag, uint64_t idx, uint64_t addr)
{
    return (tag << (cc->index_bits + cc->line_bits)) + (idx << cc->line_bits) + addr;
}

static void cachePromoteNode(CMMHCache *cc, uint64_t idx, CacheNode *curr)
{
    CacheNode *prev = curr->prev;
    CacheNode *next = curr->next;

    if(prev)
        prev->next = next;
    
    if(next)
        next->prev = prev;

    CacheNode **head = &(cc->table[idx]);

    curr->next = *head;
    curr->next->prev = curr;
    curr->prev = NULL;
    *head = curr;
}

/*
    access to the proposed cache entry
    if exist: return the pointer of the entry, victim = UINT64_MAX
    else:   return the pointer of the victim entry(LRU rule), victim = (dpa of the entry)
*/

static CacheNode* cache_access(CMMHCache *cc, uint64_t dpa, uint64_t *victim)
{
    cmmh_cache_log("%s, CMMH Cache access [Entered] at [%x]!\n", "CACHE", dpa);
    uint64_t tag = getCacheTag(cc, dpa);
    uint64_t idx = getCacheIdx(cc, dpa);
    
    CacheNode *curr = cc->table[idx];
    CacheNode *bef;
    while(curr) {
        if(curr->valid && curr->tag == tag) {
            cachePromoteNode(cc, idx, curr);
            cc->cache_hit ++;
            return curr;
        }
        bef = curr;
        curr = curr->next;
    }

    /* CACHE MISS */
    cc->cache_miss++;
    *victim = get_dpa(cc, bef->tag, idx, 0);
    return bef;
}

/*
    Modify the given entry; set difty flag
*/

static void cache_modify(CMMHCache* cc, CacheNode* cn)
{
    cmmh_cache_log("%s, CMMH Cache modify [Entered]!\n", "CACHE");
    cn->dirty = true;
}

/*
    Fill the cache with the given dpa
    Promote the node(LRU rule)
    set valid, unset dirty
    set tag corr.to given dpa
*/

static void cache_fill(CMMHCache* cc, CacheNode* cn, uint64_t dpa)
{
    uint64_t tag = getCacheTag(cc, dpa);
    uint64_t idx = getCacheIdx(cc, dpa);

    cachePromoteNode(cc, idx, cn);
    cn->valid = true;
    cn->dirty = false;
    cn->tag = tag;
}

void cmmh_cache_init(CMMHCache *cache, uint16_t pg_bits)
{
    //cmmh_cache_log("%s, CMMH Cache initialization [Entered]!\n", "CACHYEE");
    /* Currently single NAND Flash page size */
    cache->line_bits = pg_bits;
    int index_bits  = cache->index_bits;
    int num_tag     = cache->num_tag;

    cache->table = g_malloc0(sizeof(CacheNode*) * (1 << index_bits));
    for(int i = 0; i < (1 << index_bits); i++) {
        cache->table[i] = NULL;
        for(int j = 0; j < num_tag; j++) {
            CacheNode* curr = g_malloc0(sizeof(CacheNode));
            curr->dirty = false;
            curr->valid = false;
            if(cache->table[i] != NULL)
                cache->table[i]->prev = curr;
            curr->next = cache->table[i];
            curr->prev = NULL;
            cache->table[i] = curr;
        }
    }
    
    cache->access = cache_access;
    cache->modify = cache_modify;
    cache->fill = cache_fill;

    /* STATUS INIT */
    cache->cache_hit = 0;
    cache->cache_miss = 0;
    //cmmh_cache_log("%s, CMMH Cache initialization [FINISHED]!\n", "CACHYEE");
}