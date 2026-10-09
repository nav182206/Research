/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6431
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2f07f81a2d52d9d5243ead61d93e875487acf70
 */

static void breakpoint_invalidate(CPUState *env, target_ulong pc)

{

    target_ulong phys_addr;



    phys_addr = cpu_get_phys_page_debug(env, pc);

    tb_invalidate_phys_page_range(phys_addr, phys_addr + 1, 0);

}
