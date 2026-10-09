/* 
 * Benchmark Sample ID : devign_6056
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

PPC_OP(test_ctr_false)

{

    T0 = (regs->ctr != 0 && (T0 & PARAM(1)) == 0);

    RETURN();

}
