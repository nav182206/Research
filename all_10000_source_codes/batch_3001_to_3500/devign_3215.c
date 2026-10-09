/* 
 * Benchmark Sample ID : devign_3215
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9dbbc748d671c70599101836cd1c2719d92f3017
 */

static inline void assert_fp_access_checked(DisasContext *s)

{

#ifdef CONFIG_DEBUG_TCG

    if (unlikely(!s->fp_access_checked || !s->cpacr_fpen)) {

        fprintf(stderr, "target-arm: FP access check missing for "

                "instruction 0x%08x\n", s->insn);

        abort();

    }

#endif

}
