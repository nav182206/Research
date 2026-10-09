/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6673
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d1628e832dfc6ec02b0d196f6cc250aaa7bf3b3
 */

uint64_t helper_mulqv(CPUAlphaState *env, uint64_t op1, uint64_t op2)

{

    uint64_t tl, th;



    muls64(&tl, &th, op1, op2);

    /* If th != 0 && th != -1, then we had an overflow */

    if (unlikely((th + 1) > 1)) {

        arith_excp(env, GETPC(), EXC_M_IOV, 0);

    }

    return tl;

}
