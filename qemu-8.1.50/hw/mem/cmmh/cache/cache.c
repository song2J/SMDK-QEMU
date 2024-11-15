#include "cache.h"

void cmmh_cache_init(CMMHCache *cc, uint16_t pg_bits)
{
    cc->line_bits = pg_bits;

    switch(cc->cache_policy) {
    case LOCAL_LRU:
        cmmh_cache_local_lru_init(cc);
        break;
    case GLOBAL_LRU:
        //TODO
    default:
        cmmh_cache_local_lru_init(cc);
    }
}