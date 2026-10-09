/* 
 * Benchmark Sample ID : devign_4394
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2be0e25f4b6a4f91e39388cc365bbe53b56ab62a
 */

void memory_region_destroy(MemoryRegion *mr)

{

    assert(QTAILQ_EMPTY(&mr->subregions));


    mr->destructor(mr);

    memory_region_clear_coalescing(mr);

    g_free((char *)mr->name);

    g_free(mr->ioeventfds);

}
