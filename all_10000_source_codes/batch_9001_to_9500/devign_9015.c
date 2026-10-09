/* 
 * Benchmark Sample ID : devign_9015
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f2d8978728c48ca46f5c01835438508aace5c64
 */

void OPPROTO op_4xx_tlbsx_check (void)

{

    int tmp;



    tmp = xer_so;

    if (T0 != -1)

        tmp |= 0x02;

    env->crf[0] = tmp;

    RETURN();

}
