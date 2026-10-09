/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5848
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=76e050c2e62995f1d6905e28674dea3a7fcff1a5
 */

void op_addo (void)

{

    target_ulong tmp;



    tmp = T0;

    T0 += T1;

    if ((T0 >> 31) ^ (T1 >> 31) ^ (tmp >> 31)) {

        CALL_FROM_TB1(do_raise_exception_direct, EXCP_OVERFLOW);

    }

    RETURN();

}
