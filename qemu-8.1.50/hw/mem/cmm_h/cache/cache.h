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
    int page_size;
    int page_log_size;
    int tag_bit_len;
    int tag_bit_mask;
    int index_bit_mask;

    CacheNode **table;
    
} CMMHCache;

#endif