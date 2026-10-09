/* 
 * Benchmark Sample ID : devign_5314
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ecf5e8eae8b0b5fa41f00b53d67747b42fd1b8b9
 */

static bool pmsav7_use_background_region(ARMCPU *cpu,

                                         ARMMMUIdx mmu_idx, bool is_user)

{

    /* Return true if we should use the default memory map as a

     * "background" region if there are no hits against any MPU regions.

     */

    CPUARMState *env = &cpu->env;



    if (is_user) {

        return false;

    }



    if (arm_feature(env, ARM_FEATURE_M)) {

        return env->v7m.mpu_ctrl & R_V7M_MPU_CTRL_PRIVDEFENA_MASK;

    } else {

        return regime_sctlr(env, mmu_idx) & SCTLR_BR;

    }

}
