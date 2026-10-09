/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_38
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

void isa_mmio_init(target_phys_addr_t base, target_phys_addr_t size)

{

    MemoryRegion *mr = g_malloc(sizeof(*mr));



    isa_mmio_setup(mr, size);

    memory_region_add_subregion(get_system_memory(), base, mr);

}
