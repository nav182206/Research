/* 
 * Benchmark Sample ID : devign_5887
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

void macio_nvram_setup_bar(MacIONVRAMState *s, MemoryRegion *bar,

                           target_phys_addr_t mem_base)

{

    memory_region_add_subregion(bar, mem_base, &s->mem);

}
