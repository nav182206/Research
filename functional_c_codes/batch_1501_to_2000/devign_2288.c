/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2288
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

PPC_OP(cmpi)

{

    if (Ts0 < SPARAM(1)) {

        T0 = 0x08;

    } else if (Ts0 > SPARAM(1)) {

        T0 = 0x04;

    } else {

        T0 = 0x02;

    }

    RETURN();

}
