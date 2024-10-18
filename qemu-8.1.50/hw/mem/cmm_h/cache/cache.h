#ifndef CACHE_H
#define CACHE_H

#include <stdint.h>
#include <stdbool.h>

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

    bool (*read)(CMMHCache *cc, uint64_t dpa);
    bool (*write)(CMMHCache *cc, uint64_t dpa);
    
} CMMHCache;

extern bool cache_init(CMMHCache *cache);

#endif