/* 
 * Benchmark Sample ID : devign_4092
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

static void check_ieee_exceptions(CPUSPARCState *env)

{

    target_ulong status;



    status = get_float_exception_flags(&env->fp_status);

    if (status) {

        /* Copy IEEE 754 flags into FSR */

        if (status & float_flag_invalid) {

            env->fsr |= FSR_NVC;

        }

        if (status & float_flag_overflow) {

            env->fsr |= FSR_OFC;

        }

        if (status & float_flag_underflow) {

            env->fsr |= FSR_UFC;

        }

        if (status & float_flag_divbyzero) {

            env->fsr |= FSR_DZC;

        }

        if (status & float_flag_inexact) {

            env->fsr |= FSR_NXC;

        }



        if ((env->fsr & FSR_CEXC_MASK) & ((env->fsr & FSR_TEM_MASK) >> 23)) {

            /* Unmasked exception, generate a trap */

            env->fsr |= FSR_FTT_IEEE_EXCP;

            helper_raise_exception(env, TT_FP_EXCP);

        } else {

            /* Accumulate exceptions */

            env->fsr |= (env->fsr & FSR_CEXC_MASK) << 5;

        }

    }

}
