/* 
 * Benchmark Sample ID : devign_7846
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cecd8504b80148b66cdc1ce32046429bc3549090
 */

void HELPER(vfp_set_fpscr)(CPUState *env, uint32_t val)

{

    int i;

    uint32_t changed;



    changed = env->vfp.xregs[ARM_VFP_FPSCR];

    env->vfp.xregs[ARM_VFP_FPSCR] = (val & 0xffc8ffff);

    env->vfp.vec_len = (val >> 16) & 7;

    env->vfp.vec_stride = (val >> 20) & 3;



    changed ^= val;

    if (changed & (3 << 22)) {

        i = (val >> 22) & 3;

        switch (i) {

        case 0:

            i = float_round_nearest_even;

            break;

        case 1:

            i = float_round_up;

            break;

        case 2:

            i = float_round_down;

            break;

        case 3:

            i = float_round_to_zero;

            break;

        }

        set_float_rounding_mode(i, &env->vfp.fp_status);

    }

    if (changed & (1 << 24))

        set_flush_to_zero((val & (1 << 24)) != 0, &env->vfp.fp_status);

    if (changed & (1 << 25))

        set_default_nan_mode((val & (1 << 25)) != 0, &env->vfp.fp_status);



    i = vfp_exceptbits_to_host(val);

    set_float_exception_flags(i, &env->vfp.fp_status);

}
