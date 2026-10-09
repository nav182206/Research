/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9351
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e389be1673052b538534643165111725a79e5afd
 */

static inline bool extended_addresses_enabled(CPUARMState *env)

{

    return arm_el_is_aa64(env, 1)

        || ((arm_feature(env, ARM_FEATURE_LPAE)

             && (env->cp15.c2_control & (1U << 31))));

}
