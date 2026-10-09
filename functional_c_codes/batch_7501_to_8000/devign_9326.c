/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9326
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5d7fd045cafeac1831c1999cb9e1251b7906c6b2
 */

uint32_t HELPER(lcxbr)(CPUS390XState *env, uint32_t f1, uint32_t f2)

{

    CPU_QuadU x1, x2;



    x2.ll.upper = env->fregs[f2].ll;

    x2.ll.lower = env->fregs[f2 + 2].ll;

    x1.q = float128_chs(x2.q);

    env->fregs[f1].ll = x1.ll.upper;

    env->fregs[f1 + 2].ll = x1.ll.lower;

    return set_cc_nz_f128(x1.q);

}
