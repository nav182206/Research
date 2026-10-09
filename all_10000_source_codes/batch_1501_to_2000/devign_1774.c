/* 
 * Benchmark Sample ID : devign_1774
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

int64_t helper_fdtox(CPUSPARCState *env, float64 src)

{

    int64_t ret;

    clear_float_exceptions(env);

    ret = float64_to_int64_round_to_zero(src, &env->fp_status);

    check_ieee_exceptions(env);

    return ret;

}
