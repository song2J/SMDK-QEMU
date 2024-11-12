#ifndef CACHE_H
#define CACHE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

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
    int line_bits;
    int index_bits;
    //int tag_bits;

    int num_tag; // How many tags per each idx?
    CacheNode **table;

    CacheNode* (*access)(struct CMMHCache *cc, uint64_t dpa, uint64_t* victim);
    CacheNode* (*modify)(struct CMMHCache *cc, CacheNode *cn);
    void (*fill)(struct CMMHCache *cc, CacheNode *cn, uint64_t dpa);

    /* STATUS FIELD */ 
    uint64_t cache_hit;   
    uint64_t cache_miss;   
} CMMHCache;

extern void cmmh_cache_init(CMMHCache *cache, uint16_t pg_bits);
#define cmmh_cache_err(fmt, ...) \
    do { fprintf(stderr, "[CMMH] Cache-Err: " fmt, ## __VA_ARGS__); } while (0)

#define cmmh_cache_log(fmt, ...) \
    do { printf("[CMMH] Cache-Log: " fmt, ## __VA_ARGS__); } while (0)


#endif