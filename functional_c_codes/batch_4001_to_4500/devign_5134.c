/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5134
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9d70c4b7b8a580959cc4f739e7c9a04964d00d46
 */

static void breakpoint_invalidate(CPUArchState *env, target_ulong pc)

{

    tb_invalidate_phys_addr(cpu_get_phys_page_debug(env, pc));

}
