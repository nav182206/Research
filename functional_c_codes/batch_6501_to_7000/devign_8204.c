/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8204
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

float64 helper_fxtod(CPUSPARCState *env, int64_t src)

{

    float64 ret;

    clear_float_exceptions(env);

    ret = int64_to_float64(src, &env->fp_status);

    check_ieee_exceptions(env);

    return ret;

}
