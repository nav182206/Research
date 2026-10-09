/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4600
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=37654d9e6af84003982f8b9a5d59a4aef28e0a79
 */

static inline void _t_gen_mov_env_TN(int offset, TCGv tn)

{

    if (offset > sizeof(CPUCRISState)) {

        fprintf(stderr, "wrong store to env at off=%d\n", offset);

    }

    tcg_gen_st_tl(tn, cpu_env, offset);

}
