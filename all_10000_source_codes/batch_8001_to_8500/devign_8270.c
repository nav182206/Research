/* 
 * Benchmark Sample ID : devign_8270
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static inline void t_gen_sext(TCGv d, TCGv s, int size)

{

	if (size == 1)

		tcg_gen_ext8s_i32(d, s);

	else if (size == 2)

		tcg_gen_ext16s_i32(d, s);

	else if(GET_TCGV(d) != GET_TCGV(s))

		tcg_gen_mov_tl(d, s);

}
