/* 
 * Benchmark Sample ID : devign_8130
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_subfe (void)

{

    T0 = T1 + ~T0 + xer_ca;

    if (likely(T0 >= T1 && (xer_ca == 0 || T0 != T1))) {

        xer_ca = 0;

    } else {

        xer_ca = 1;

    }

}
