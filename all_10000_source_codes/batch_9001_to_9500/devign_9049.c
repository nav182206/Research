/* 
 * Benchmark Sample ID : devign_9049
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bb593904c18e22ea0671dfa1b02e24982f2bf0ea
 */

static void spr_read_sdr1 (void *opaque, int gprn, int sprn)

{

    tcg_gen_ld_tl(cpu_gpr[gprn], cpu_env, offsetof(CPUState, sdr1));

}
