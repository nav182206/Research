/* 
 * Benchmark Sample ID : devign_4486
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=deb2db996cbb9470b39ae1e383791ef34c4eb3c2
 */

bool arm_regime_using_lpae_format(CPUARMState *env, ARMMMUIdx mmu_idx)

{

    return regime_using_lpae_format(env, mmu_idx);

}
