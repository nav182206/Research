/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8331
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b67ea0cd74417b42482499c29feb90914fbf8097
 */

void tlb_fill(target_ulong addr, int is_write, int mmu_idx, void *retaddr)

{

    tlb_set_page(cpu_single_env,

            addr & ~(TARGET_PAGE_SIZE - 1),

            addr & ~(TARGET_PAGE_SIZE - 1),

            PAGE_READ | PAGE_WRITE | PAGE_EXEC,

            mmu_idx, TARGET_PAGE_SIZE);

}
