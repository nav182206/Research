/* 
 * Benchmark Sample ID : devign_2308
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static void t_gen_asr(TCGv d, TCGv a, TCGv b)

{

	TCGv t0, t_31;



	t0 = tcg_temp_new(TCG_TYPE_TL);

	t_31 = tcg_temp_new(TCG_TYPE_TL);

	tcg_gen_sar_tl(d, a, b);



	tcg_gen_movi_tl(t_31, 31);

	tcg_gen_sub_tl(t0, t_31, b);

	tcg_gen_sar_tl(t0, t0, t_31);

	tcg_gen_or_tl(d, d, t0);

	tcg_temp_free(t0);

	tcg_temp_free(t_31);

}
