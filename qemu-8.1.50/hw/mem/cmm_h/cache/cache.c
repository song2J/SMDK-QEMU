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

static CacheNode* cache_read(CMMHCache *cc, uint64_t dpa, uint64_t *victim)
{
    cmmh_cache_log("%s, CMMH Cache read [Entered]!\n", "CACHE");
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

static CacheNode* cache_write(CMMHCache *cc, uint64_t dpa, uint64_t *victim)
{
    cmmh_cache_log("%s, CMMH Cache write [Entered]!\n", "CACHE");
    uint64_t tag = getCacheTag(cc, dpa);
    uint64_t idx = getCacheIdx(cc, dpa);
    
    CacheNode *curr = cc->table[idx];
    CacheNode *bef;
    while(curr) {
        if(curr->valid && curr->tag == tag) {
            curr->dirty = true;
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

static void cache_fill(CMMHCache* cc, CacheNode* cn, uint64_t dpa)
{
    uint64_t tag = getCacheTag(cc, dpa);
    uint64_t idx = getCacheIdx(cc, dpa);

    cachePromoteNode(cc, idx, cn);
    cn->dirty = false;
    cn->valid = true;
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
            cache->table[i] = curr;
        }
    }
    
    cache->read = cache_read;
    cache->write = cache_write;
    cache->fill = cache_fill;

    /* STATUS INIT */
    cache->cache_hit = 0;
    cache->cache_miss = 0;
    //cmmh_cache_log("%s, CMMH Cache initialization [FINISHED]!\n", "CACHYEE");
}