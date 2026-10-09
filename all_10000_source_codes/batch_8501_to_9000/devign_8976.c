/* 
 * Benchmark Sample ID : devign_8976
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ec05ec26f940564b1e07bf88857035ec27e21dd8
 */

void memory_region_ram_resize(MemoryRegion *mr, ram_addr_t newsize, Error **errp)

{

    assert(mr->terminates);



    qemu_ram_resize(mr->ram_addr, newsize, errp);

}
