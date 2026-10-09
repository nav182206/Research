/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5730
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=26a83ad0e793465b74a8b06a65f2f6fdc5615413
 */

static void memory_region_prepare_ram_addr(MemoryRegion *mr)

{

    if (mr->backend_registered) {

        return;

    }



    mr->destructor = memory_region_destructor_iomem;

    mr->ram_addr = cpu_register_io_memory(memory_region_read_thunk,

                                          memory_region_write_thunk,

                                          mr);

    mr->backend_registered = true;

}
