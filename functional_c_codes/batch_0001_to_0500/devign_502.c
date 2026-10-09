/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_502
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a718978ed58abc1ad92567a9c17525136be02a71
 */

static int32_t ide_nop_int32(IDEDMA *dma, int x)

{

    return 0;

}
