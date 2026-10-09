/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8219
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8d5c773e323b22402abdd0beef4c7d2fc91dd0eb
 */

static void vmsa_ttbcr_reset(CPUARMState *env, const ARMCPRegInfo *ri)

{

    env->cp15.c2_base_mask = 0xffffc000u;

    env->cp15.c2_control = 0;

    env->cp15.c2_mask = 0;

}
