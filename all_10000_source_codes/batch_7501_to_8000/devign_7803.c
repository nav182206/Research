/* 
 * Benchmark Sample ID : devign_7803
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

float64 helper_fqtod(CPUSPARCState *env)

{

    float64 ret;

    clear_float_exceptions(env);

    ret = float128_to_float64(QT1, &env->fp_status);

    check_ieee_exceptions(env);

    return ret;

}
