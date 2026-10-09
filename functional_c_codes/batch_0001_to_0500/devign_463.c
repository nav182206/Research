/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_463
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2aaa1940684a3bf2b381fd2a8ff26c287a05109d
 */

static uint32_t cc_calc_abs_64(int64_t dst)

{

    if ((uint64_t)dst == 0x8000000000000000ULL) {

        return 3;

    } else if (dst) {

        return 1;

    } else {

        return 0;

    }

}
