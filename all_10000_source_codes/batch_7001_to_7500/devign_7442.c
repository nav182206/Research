/* 
 * Benchmark Sample ID : devign_7442
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static inline void t_gen_swapw(TCGv d, TCGv s)

{

	TCGv t;

	/* d and s refer the same object.  */

	t = tcg_temp_new(TCG_TYPE_TL);

	tcg_gen_mov_tl(t, s);

	tcg_gen_shli_tl(d, t, 16);

	tcg_gen_shri_tl(t, t, 16);

	tcg_gen_or_tl(d, d, t);

	tcg_temp_free(t);

}
