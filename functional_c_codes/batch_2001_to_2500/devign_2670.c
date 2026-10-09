/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2670
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=26a83ad0e793465b74a8b06a65f2f6fdc5615413
 */

ram_addr_t memory_region_get_ram_addr(MemoryRegion *mr)

{

    assert(mr->backend_registered);

    return mr->ram_addr;

}
