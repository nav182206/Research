/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3495
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d30107814c8d02f1896bd57249aef1b5aaed38c9
 */

int64_t HELPER(nabs_i64)(int64_t val)

{

    if (val < 0) {

        return val;

    } else {

        return -val;

    }

}
