/* 
 * Benchmark Sample ID : devign_7385
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_nego (void)

{

    if (likely(T0 != INT32_MIN)) {

        xer_ov = 0;

        T0 = -Ts0;

    } else {

        xer_ov = 1;

        xer_so = 1;

    }

}
