/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6227
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_405_check_ov (void)

{

    if (likely(((T1 ^ T2) >> 31) || !((T0 ^ T2) >> 31))) {

        xer_ov = 0;

    } else {

        xer_ov = 1;

        xer_so = 1;

    }

}
