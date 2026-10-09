/* 
 * Benchmark Sample ID : devign_6944
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8d5c773e323b22402abdd0beef4c7d2fc91dd0eb
 */

static void dacr_write(CPUARMState *env, const ARMCPRegInfo *ri, uint64_t value)

{

    ARMCPU *cpu = arm_env_get_cpu(env);



    env->cp15.c3 = value;

    tlb_flush(CPU(cpu), 1); /* Flush TLB as domain not tracked in TLB */

}
