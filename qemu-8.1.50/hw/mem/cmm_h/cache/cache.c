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

bool isCacheHit(CMMHCache* cc, uint64_t dpa, bool if_modify)
{
    uint64_t tag = getCacheTag(cc, dpa);
    uint64_t idx = getCacheIdx(cc, dpa);
    
    CacheNode *curr = cc->table[idx];
    CacheNode *bef;
    while(curr) {
        if(curr->valid && curr->tag == tag) {
            curr->dirty |= if_modify;
            cachePromoteNode(cc, idx, curr);
            return true;
        }
        bef = curr;
        curr = curr->next;
    }
    /* Evict victim */
    bef->tag = tag;
    if(bef->dirty) {
        /* TODO: NAND Write latency */
    }

    /* TODO: NAND Read latency */
    curr->dirty = if_modify;
    cachePromoteNode(cc, idx, bef);

    return false;
}

bool cache_read(CMMHCache *cc, uint64_t dpa)
{
    if(isCacheHit(cc, dpa, false)) {
        /* count read cache hit */
    } else {
        /* count read cache miss*/
    }
}

bool cache_write(CMMHCache *cc, uint64_t dpa)
{
    if(isCacheHit(cc, dpa, true)) {
        /* count write cache hit */
    } else {
        /* count write cache miss*/
    }
    
}

static bool cache_init(CMMHCache *cache)
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