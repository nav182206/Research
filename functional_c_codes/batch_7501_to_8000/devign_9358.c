/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9358
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2958620f67dcfd11476e62b4ca704dae0b978ea3
 */

uint64_t helper_mullv (uint64_t op1, uint64_t op2)

{

    int64_t res = (int64_t)op1 * (int64_t)op2;



    if (unlikely((int32_t)res != res)) {

        arith_excp(env, GETPC(), EXC_M_IOV, 0);

    }

    return (int64_t)((int32_t)res);

}
