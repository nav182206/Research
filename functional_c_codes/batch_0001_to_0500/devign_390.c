/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_390
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4e47e39ab0ded72c0af174131ecf49d588d66c12
 */

void helper_ldmxcsr(CPUX86State *env, uint32_t val)

{

    env->mxcsr = val;

    update_sse_status(env);

}
