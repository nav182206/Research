/* 
 * Benchmark Sample ID : devign_4703
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

static inline void set_fsr(CPUSPARCState *env)

{

    int rnd_mode;



    switch (env->fsr & FSR_RD_MASK) {

    case FSR_RD_NEAREST:

        rnd_mode = float_round_nearest_even;

        break;

    default:

    case FSR_RD_ZERO:

        rnd_mode = float_round_to_zero;

        break;

    case FSR_RD_POS:

        rnd_mode = float_round_up;

        break;

    case FSR_RD_NEG:

        rnd_mode = float_round_down;

        break;

    }

    set_float_rounding_mode(rnd_mode, &env->fp_status);

}
