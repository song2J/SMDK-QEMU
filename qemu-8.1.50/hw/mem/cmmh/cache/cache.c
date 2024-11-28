#include "cache.h"

void cmmh_cache_init(CMMHCache *cc, uint16_t pg_bits)
{
    cc->line_bits = pg_bits;

    switch((CachePolicy)cc->cache_policy) {
    case LOCAL_LRU:
        cmmh_cache_local_lru_init(cc);
        break;
    case GLOBAL_LRU:
        cmmh_cache_global_lru_init(cc);
        break;
    case DIP:
        cmmh_cache_dip_init(cc);
    default:
        cmmh_cache_local_lru_init(cc);
    }
}