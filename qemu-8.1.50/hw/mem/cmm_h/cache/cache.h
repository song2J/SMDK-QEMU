#ifndef CACHE_H
#define CACHE_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    HIT = 0,
    MISS_CLEAN,
    MISS_DIRTY,
} CacheAccessResult;

typedef struct CacheNode {
    uint64_t tag;
    bool valid;
    bool dirty;

    struct CacheNode *prev;
    struct CacheNode *next;
} CacheNode;

typedef struct CMMHCache {
    int page_bits;
    int index_bits;
    int tag_bits;

    int num_tag; // How many tags per each idx?
    CacheNode **table;

    CacheAccessResult (*read)(CMMHCache *cc, uint64_t dpa, uint64_t* victim);
    CacheAccessResult (*write)(CMMHCache *cc, uint64_t dpa, uint64_t* victim);
    
} CMMHCache;

extern void cmmh_cache_init(CMMHCache *cache);

#endif