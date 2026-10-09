/* 
 * Benchmark Sample ID : devign_9906
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2aaa1940684a3bf2b381fd2a8ff26c287a05109d
 */

static uint32_t cc_calc_abs_32(int32_t dst)

{

    if ((uint32_t)dst == 0x80000000UL) {

        return 3;

    } else if (dst) {

        return 1;

    } else {

        return 0;

    }

}
