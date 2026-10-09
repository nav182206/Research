/* 
 * Benchmark Sample ID : devign_6759
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d1628e832dfc6ec02b0d196f6cc250aaa7bf3b3
 */

uint64_t helper_addlv(CPUAlphaState *env, uint64_t op1, uint64_t op2)

{

    uint64_t tmp = op1;

    op1 = (uint32_t)(op1 + op2);

    if (unlikely((tmp ^ op2 ^ (-1UL)) & (tmp ^ op1) & (1UL << 31))) {

        arith_excp(env, GETPC(), EXC_M_IOV, 0);

    }

    return op1;

}
