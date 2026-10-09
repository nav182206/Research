/* 
 * Benchmark Sample ID : devign_7683
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8d5c773e323b22402abdd0beef4c7d2fc91dd0eb
 */

static void fcse_write(CPUARMState *env, const ARMCPRegInfo *ri, uint64_t value)

{

    ARMCPU *cpu = arm_env_get_cpu(env);



    if (env->cp15.c13_fcse != value) {

        /* Unlike real hardware the qemu TLB uses virtual addresses,

         * not modified virtual addresses, so this causes a TLB flush.

         */

        tlb_flush(CPU(cpu), 1);

        env->cp15.c13_fcse = value;

    }

}
