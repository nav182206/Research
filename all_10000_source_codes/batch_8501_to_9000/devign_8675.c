/* 
 * Benchmark Sample ID : devign_8675
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

PPC_OP(btest_T1) 

{

    if (T0) {

        regs->nip = T1 & ~3;

    } else {

        regs->nip = PARAM1;

    }

    RETURN();

}
