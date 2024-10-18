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

bool cacheRead(CMMHCache *cc, uint64_t dpa)
{
    if(isCacheHit(cc, dpa, false)) {
        /* count cache hit */
    } else {
        /* count cache miss*/
    }
}

bool cacheWrite(CMMHCache *cc, uint64_t dpa)
{
    if(isCacheHit(cc, dpa, true)) {
        /* count cache hit */
    } else {
        /* count cache miss*/
    }
    
}

static bool cacheInit(CMMHCache **ccp, FemuCtrl* fc)
{
    *ccp = g_malloc0(sizeof(CMMHCache));

    int page_bits  = fc->page_bits; // NOT SURE IF IT CAN BE USED
    int index_bits = fc->cache_index_bits;
    int num_tag     = fc->cache_num_tag;

    (*ccp)->page_bits = page_bits;
    (*ccp)->index_bits = index_bits;
    (*ccp)->tag_bits = sizeof(void*) - page_bits - index_bits;

    (*ccp)->num_tag = num_tag;

    (*ccp)->table = g_malloc0(sizeof(CacheNode*) * index_bits);
    for(int i = 0; i < (1 << index_bits); i++) {
        for(int j = 0; j < num_tag; j++) {
            CacheNode* curr = g_malloc0(sizeof(CacheNode));
            curr->next = (*ccp)->table[i];
            (*ccp)->table[i] = curr;
        }
    }

    (*ccp)->read = cacheRead;
    (*ccp)->write = cacheWrite;
}