/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_274
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14a1120e5c8c4c29441141b4657f91e04d10fac0
 */

void OPPROTO op_udivx_T1_T0(void)

{




    T0 /= T1;

    FORCE_RET();
