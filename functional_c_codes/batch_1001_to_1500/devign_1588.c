/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1588
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c5a49c63fa26e8825ad101dfe86339ae4c216539
 */

static inline bool use_goto_tb(DisasContext *s, int n, uint64_t dest)

{

    /* No direct tb linking with singlestep (either QEMU's or the ARM

     * debug architecture kind) or deterministic io

     */

    if (s->base.singlestep_enabled || s->ss_active || (s->base.tb->cflags & CF_LAST_IO)) {

        return false;

    }



#ifndef CONFIG_USER_ONLY

    /* Only link tbs from inside the same guest page */

    if ((s->base.tb->pc & TARGET_PAGE_MASK) != (dest & TARGET_PAGE_MASK)) {

        return false;

    }

#endif



    return true;

}
