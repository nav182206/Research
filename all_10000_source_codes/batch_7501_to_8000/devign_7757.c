/* 
 * Benchmark Sample ID : devign_7757
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

void helper_ldfsr(CPUSPARCState *env, uint32_t new_fsr)

{

    env->fsr = (new_fsr & FSR_LDFSR_MASK) | (env->fsr & FSR_LDFSR_OLDMASK);

    set_fsr(env);

}
