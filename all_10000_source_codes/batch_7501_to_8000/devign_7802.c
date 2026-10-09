/* 
 * Benchmark Sample ID : devign_7802
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f7c11b535040df31cc8bc3b1f0c33f546073ee62
 */

static void tlb_unprotect_code_phys(CPUState *env, ram_addr_t ram_addr,

                                    target_ulong vaddr)

{

    phys_ram_dirty[ram_addr >> TARGET_PAGE_BITS] |= CODE_DIRTY_FLAG;

}
