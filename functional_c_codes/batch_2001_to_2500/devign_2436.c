/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2436
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

PPC_OP(addc)

{

    T2 = T0;

    T0 += T1;

    if (T0 < T2) {

        xer_ca = 1;

    } else {

        xer_ca = 0;

    }

    RETURN();

}
