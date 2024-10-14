#include "cache.h"

inline uint64_t getCacheTag(CMMHCache* cc, uint64_t dpa)
{
    return (dpa & cc->tag_bit_mask) >> (cc->page_log_size);
}

inline uint64_t getCacheIdx(CMMHCache* cc, uint64_t dpa)
{
    return (dpa & cc->index_bit_mask) >> (cc->tag_bit_len + cc->page_log_size);
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

static bool cacheRead(CMMHCache *cc, uint64_t dpa)
{
    if(isCacheHit(cc, dpa, false)) {
        /* count cache hit */
    } else {
        /* count cache miss*/
    }
}

static bool cacheWrite(CMMHCache *cc, uint64_t dpa)
{
    if(isCacheHit(cc, dpa, true)) {
        /* count cache hit */
    } else {
        /* count cache miss*/
    }
    
}

static bool cacheInit(CMMHCache **ccp)
{
    
}