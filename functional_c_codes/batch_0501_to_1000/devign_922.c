/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_922
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_405_check_sat (void)

{

    if (!likely(((T1 ^ T2) >> 31) || !((T0 ^ T2) >> 31))) {

        /* Saturate result */

        if (T2 >> 31) {

            T0 = INT32_MIN;

        } else {

            T0 = INT32_MAX;

        }

    }

}
