#include "cache.h"

inline uint64_t getCacheOffset(CMMHCache* cc, uint64_t dpa)
{
    return (dpa & ((1 << cc->page_bits) - 1));
}

inline uint64_t getCacheTag(CMMHCache* cc, uint64_t dpa)
{
    return (dpa >> (cc->page_bits + cc->index_bits)) & ((1 << (cc->tag_bits)) - 1);
}

inline uint64_t getCacheIdx(CMMHCache* cc, uint64_t dpa)
{
    return (dpa >> (cc->page_bits)) & ((1 << (cc->index_bits)) - 1);
}

inline uint64_t get_dpa(CMMHCache *cc, uint64_t tag, uint64_t idx, uint64_t addr)
{
    return (tag << (cc->index_bits + cc->page_bits)) + (idx << cc->page_bits) + addr;
}

void cachePromoteNode(CMMHCache *cc, uint64_t idx, CacheNode *curr)
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

CacheAccessResult accessCache(CMMHCache* cc, uint64_t dpa, 
                bool if_modify, uint64_t *victim)
{
    uint64_t tag = getCacheTag(cc, dpa);
    uint64_t idx = getCacheIdx(cc, dpa);
    bool evict_dirty;
    
    CacheNode *curr = cc->table[idx];
    CacheNode *bef;
    while(curr) {
        if(curr->valid && curr->tag == tag) {
            curr->dirty |= if_modify;
            cachePromoteNode(cc, idx, curr);
            return HIT;
        }
        bef = curr;
        curr = curr->next;
    }

    /* CACHE MISS */
    *victim = get_dpa(cc, bef->tag, idx, 0);
    evict_dirty = bef->dirty;
    bef->tag = tag;

    curr->dirty = if_modify;
    cachePromoteNode(cc, idx, bef);

    return evict_dirty ? MISS_DIRTY : MISS_CLEAN;
}

CacheAccessResult cache_read(CMMHCache *cc, uint64_t dpa, uint64_t *victim)
{
    return accessCache(cc, dpa, false, victim);
}

CacheAccessResult cache_write(CMMHCache *cc, uint64_t dpa, uint64_t *victim)
{
    return accessCache(cc, dpa, true, victim);
}

static void cache_init(CMMHCache *cache)
{
    int index_bits  = cache->index_bits;
    int num_tag     = cache->num_tag;

    cache->table = g_malloc0(sizeof(CacheNode*) * index_bits);
    for(int i = 0; i < (1 << index_bits); i++) {
        for(int j = 0; j < num_tag; j++) {
            CacheNode* curr = g_malloc0(sizeof(CacheNode));
            cache->table[i]->prev = curr;
            curr->next = cache->table[i];
            cache->table[i] = curr;
        }
    }

    cache->read = cache_read;
    cache->write = cache_write;
}