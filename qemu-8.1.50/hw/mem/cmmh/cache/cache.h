#ifndef CACHE_H
#define CACHE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*
    common data: dpa with validity / dirty flag
    Policy-specific additional info will be
        on 'policy_specific_data'
*/
typedef struct CacheLine {
    uint64_t dpa;
    bool valid;
    bool dirty;

    void* policy_specific_data;
} CacheLine;

typedef enum{
    LOCAL_LRU = 1,
    GLOBAL_LRU,
    SKIPLIST
} CachePolicy;

typedef struct CMMHCache {
    int32_t cache_policy;

    int line_bits;
    int index_bits;
    int num_tag; // How many tags per each idx?
    void* table; // Policy-specific cache table

    CacheLine* (*access)(struct CMMHCache *cc, uint64_t dpa, uint64_t* victim);
    void (*modify)(struct CMMHCache *cc, CacheLine *cn);
    void (*fill)(struct CMMHCache *cc, CacheLine *cn, uint64_t dpa);
    void (*flush)(struct CMMHCache *cc);
    CacheLine *(*get_valid_head_line)(struct CMMHCache *cc);
    CacheLine *(*advance_valid_line)(struct CMMHCache *cc, CacheLine *cn);

    /* STATUS FIELD */ 
    uint64_t cache_hit;   
    uint64_t cache_miss;   
} CMMHCache;

extern void cmmh_cache_init(CMMHCache *cc, uint16_t pg_bits);

extern void cmmh_cache_local_lru_init(CMMHCache* cc); 

#define cmmh_cache_err(fmt, ...) \
    do { fprintf(stderr, "[CMMH] Cache-Err: " fmt, ## __VA_ARGS__); } while (0)

#define cmmh_cache_log(fmt, ...) \
    do { printf("[CMMH] Cache-Log: " fmt, ## __VA_ARGS__); } while (0)

#endif