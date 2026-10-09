/* 
 * Benchmark Sample ID : devign_3971
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6fc76aa9adc1c8896a97059f12a1e5e6c1820c64
 */

static void hash32_bat_size(CPUPPCState *env, target_ulong *blp, int *validp,

                            target_ulong batu, target_ulong batl)

{

    target_ulong bl;

    int valid;



    bl = (batu & BATU32_BL) << 15;

    valid = 0;

    if (((msr_pr == 0) && (batu & BATU32_VS)) ||

        ((msr_pr != 0) && (batu & BATU32_VP))) {

        valid = 1;

    }

    *blp = bl;

    *validp = valid;

}
