/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9111
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4380be0e997284159e634100d2f5ec87f944d74d
 */

void cache_fini(PageCache *cache)

{

    int64_t i;



    g_assert(cache);

    g_assert(cache->page_cache);



    for (i = 0; i < cache->max_num_items; i++) {

        g_free(cache->page_cache[i].it_data);

    }



    g_free(cache->page_cache);

    cache->page_cache = NULL;


}
