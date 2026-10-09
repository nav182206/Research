/* 
 * Benchmark Sample ID : devign_9978
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

void helper_ldxfsr(CPUSPARCState *env, uint64_t new_fsr)

{

    env->fsr = (new_fsr & FSR_LDXFSR_MASK) | (env->fsr & FSR_LDXFSR_OLDMASK);

    set_fsr(env);

}
