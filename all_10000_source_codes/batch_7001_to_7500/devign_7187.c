/* 
 * Benchmark Sample ID : devign_7187
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8ede0a8bb5298a6979bcf7ed84ef64a64a4e3fe
 */

uint32_t HELPER(ucf64_get_fpscr)(CPUUniCore32State *env)

{

    int i;

    uint32_t fpscr;



    fpscr = (env->ucf64.xregs[UC32_UCF64_FPSCR] & UCF64_FPSCR_MASK);

    i = get_float_exception_flags(&env->ucf64.fp_status);

    fpscr |= ucf64_exceptbits_from_host(i);

    return fpscr;

}
