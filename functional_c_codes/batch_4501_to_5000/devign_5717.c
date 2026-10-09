/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5717
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8ede0a8bb5298a6979bcf7ed84ef64a64a4e3fe
 */

static inline int ucf64_exceptbits_to_host(int target_bits)

{

    int host_bits = 0;



    if (target_bits & UCF64_FPSCR_FLAG_INVALID) {

        host_bits |= float_flag_invalid;

    }

    if (target_bits & UCF64_FPSCR_FLAG_DIVZERO) {

        host_bits |= float_flag_divbyzero;

    }

    if (target_bits & UCF64_FPSCR_FLAG_OVERFLOW) {

        host_bits |= float_flag_overflow;

    }

    if (target_bits & UCF64_FPSCR_FLAG_UNDERFLOW) {

        host_bits |= float_flag_underflow;

    }

    if (target_bits & UCF64_FPSCR_FLAG_INEXACT) {

        host_bits |= float_flag_inexact;

    }

    return host_bits;

}
