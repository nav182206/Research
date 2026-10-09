/* 
 * Benchmark Sample ID : devign_9206
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

PPC_OP(extsb)

{

    T0 = (int32_t)((int8_t)(Ts0));

    RETURN();

}
