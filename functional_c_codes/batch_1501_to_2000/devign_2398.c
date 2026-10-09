/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2398
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bbc01ca7f265f2c5be8aee7c9ce1d10aa26063f5
 */

static int check_pow_970MP (CPUPPCState *env)

{

    if (env->spr[SPR_HID0] & 0x01C00000)

        return 1;



    return 0;

}
