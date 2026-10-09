/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4119
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ec05ec26f940564b1e07bf88857035ec27e21dd8
 */

void memory_region_reset_dirty(MemoryRegion *mr, hwaddr addr,

                               hwaddr size, unsigned client)

{

    assert(mr->terminates);

    cpu_physical_memory_test_and_clear_dirty(mr->ram_addr + addr, size,

                                             client);

}
