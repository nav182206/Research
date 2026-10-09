/* 
 * Benchmark Sample ID : devign_608
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2958620f67dcfd11476e62b4ca704dae0b978ea3
 */

uint64_t helper_addqv (uint64_t op1, uint64_t op2)

{

    uint64_t tmp = op1;

    op1 += op2;

    if (unlikely((tmp ^ op2 ^ (-1ULL)) & (tmp ^ op1) & (1ULL << 63))) {

        arith_excp(env, GETPC(), EXC_M_IOV, 0);

    }

    return op1;

}
