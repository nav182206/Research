/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9035
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d1628e832dfc6ec02b0d196f6cc250aaa7bf3b3
 */

uint64_t helper_subqv(CPUAlphaState *env, uint64_t op1, uint64_t op2)

{

    uint64_t res;

    res = op1 - op2;

    if (unlikely((op1 ^ op2) & (res ^ op1) & (1ULL << 63))) {

        arith_excp(env, GETPC(), EXC_M_IOV, 0);

    }

    return res;

}
