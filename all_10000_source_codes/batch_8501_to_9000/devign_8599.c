/* 
 * Benchmark Sample ID : devign_8599
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8ede0a8bb5298a6979bcf7ed84ef64a64a4e3fe
 */

float64 HELPER(ucf64_subd)(float64 a, float64 b, CPUUniCore32State *env)

{

    return float64_sub(a, b, &env->ucf64.fp_status);

}
