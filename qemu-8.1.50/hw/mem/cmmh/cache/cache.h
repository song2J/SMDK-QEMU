#ifndef CACHE_H
#define CACHE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct CacheLine {
    uint64_t dpa;
    bool valid;
    bool dirty;

    struct CacheLine *prev;
    struct CacheLine *next;
} CacheLine;

typedef struct CMMHCache {
    int line_bits;
    int index_bits;
    //int tag_bits;

    int num_tag; // How many tags per each idx?
    CacheLine **table;

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

extern void cmmh_cache_init(CMMHCache *cache, uint16_t pg_bits);
#define cmmh_cache_err(fmt, ...) \
    do { fprintf(stderr, "[CMMH] Cache-Err: " fmt, ## __VA_ARGS__); } while (0)

#define cmmh_cache_log(fmt, ...) \
    do { printf("[CMMH] Cache-Log: " fmt, ## __VA_ARGS__); } while (0)


#endif