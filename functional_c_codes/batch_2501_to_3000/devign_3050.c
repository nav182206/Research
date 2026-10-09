/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3050
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9824d01d5d789a57d27360c0f5e8ee44955eb1d7
 */

uint64_t helper_mulldo(CPUPPCState *env, uint64_t arg1, uint64_t arg2)

{

    int64_t th;

    uint64_t tl;



    muls64(&tl, (uint64_t *)&th, arg1, arg2);

    /* If th != 0 && th != -1, then we had an overflow */

    if (likely((uint64_t)(th + 1) <= 1)) {

        env->ov = 0;

    } else {

        env->so = env->ov = 1;

    }

    return (int64_t)tl;

}
