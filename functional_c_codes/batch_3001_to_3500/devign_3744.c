/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3744
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=27af7d6ea5015e5ef1f7985eab94a8a218267a2b
 */

bool cache_is_cached(const PageCache *cache, uint64_t addr)

{

    size_t pos;



    g_assert(cache);

    g_assert(cache->page_cache);



    pos = cache_get_cache_pos(cache, addr);



    return (cache->page_cache[pos].it_addr == addr);

}
