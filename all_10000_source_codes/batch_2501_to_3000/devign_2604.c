/* 
 * Benchmark Sample ID : devign_2604
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2958620f67dcfd11476e62b4ca704dae0b978ea3
 */

uint64_t helper_mulqv (uint64_t op1, uint64_t op2)

{

    uint64_t tl, th;



    muls64(&tl, &th, op1, op2);

    /* If th != 0 && th != -1, then we had an overflow */

    if (unlikely((th + 1) > 1)) {

        arith_excp(env, GETPC(), EXC_M_IOV, 0);

    }

    return tl;

}
