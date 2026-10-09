/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9437
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=212df029754caabba45f941fbd22ec219b934ef9
 */

void cpu_alpha_store_fpcr (CPUState *env, uint64_t val)

{

    int round_mode, mask;



    set_float_exception_flags((val >> 52) & 0x3F, &env->fp_status);



    mask = 0;

    if (val & FPCR_INVD)

        mask |= float_flag_invalid;

    if (val & FPCR_DZED)

        mask |= float_flag_divbyzero;

    if (val & FPCR_OVFD)

        mask |= float_flag_overflow;

    if (val & FPCR_UNFD)

        mask |= float_flag_underflow;

    if (val & FPCR_INED)

        mask |= float_flag_inexact;

    env->fp_status.float_exception_mask = mask;



    switch ((val >> FPCR_DYN_SHIFT) & 3) {

    case 0:

        round_mode = float_round_to_zero;

        break;

    case 1:

        round_mode = float_round_down;

        break;

    case 2:

        round_mode = float_round_nearest_even;

        break;

    case 3:


        round_mode = float_round_up;

        break;

    }

    set_float_rounding_mode(round_mode, &env->fp_status);

}
