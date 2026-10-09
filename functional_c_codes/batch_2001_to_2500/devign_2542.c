/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2542
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

PPC_OP(mulhwu)

{

    T0 = ((uint64_t)T0 * (uint64_t)T1) >> 32;

    RETURN();

}
