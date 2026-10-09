/* 
 * Benchmark Sample ID : devign_6237
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6da528d14de29138ca5ac43d6d059889dd24f464
 */

void HELPER(mvpg)(CPUS390XState *env, uint64_t r0, uint64_t r1, uint64_t r2)

{

    /* XXX missing r0 handling */

    env->cc_op = 0;

#ifdef CONFIG_USER_ONLY

    memmove(g2h(r1), g2h(r2), TARGET_PAGE_SIZE);

#else

    mvc_fast_memmove(env, TARGET_PAGE_SIZE, r1, r2);

#endif

}
