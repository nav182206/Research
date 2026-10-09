/* 
 * Benchmark Sample ID : devign_1052
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b748863a7f7d2996255dd2cb5a20e49785cc7387
 */

uint64_t helper_frsqrte(CPUPPCState *env, uint64_t arg)

{

    CPU_DoubleU farg;



    farg.ll = arg;



    if (unlikely(float64_is_neg(farg.d) && !float64_is_zero(farg.d))) {

        /* Reciprocal square root of a negative nonzero number */

        farg.ll = fload_invalid_op_excp(env, POWERPC_EXCP_FP_VXSQRT, 1);

    } else {

        if (unlikely(float64_is_signaling_nan(farg.d))) {

            /* sNaN reciprocal square root */

            fload_invalid_op_excp(env, POWERPC_EXCP_FP_VXSNAN, 1);

        }

        farg.d = float64_sqrt(farg.d, &env->fp_status);

        farg.d = float64_div(float64_one, farg.d, &env->fp_status);

    }

    return farg.ll;

}
