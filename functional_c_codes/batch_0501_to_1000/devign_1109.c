/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1109
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8ede0a8bb5298a6979bcf7ed84ef64a64a4e3fe
 */

float32 HELPER(ucf64_muls)(float32 a, float32 b, CPUUniCore32State *env)

{

    return float32_mul(a, b, &env->ucf64.fp_status);

}
