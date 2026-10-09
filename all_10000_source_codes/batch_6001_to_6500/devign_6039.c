/* 
 * Benchmark Sample ID : devign_6039
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b51910baf227f0fd64abfa7ad6d8e00150a18194
 */

static int do_break(CPUMIPSState *env, target_siginfo_t *info,

                    unsigned int code)

{

    int ret = -1;



    switch (code) {

    case BRK_OVERFLOW:

    case BRK_DIVZERO:

        info->si_signo = TARGET_SIGFPE;


        info->si_code = (code == BRK_OVERFLOW) ? FPE_INTOVF : FPE_INTDIV;



        break;

    default:





        break;

    }



    return ret;

}
