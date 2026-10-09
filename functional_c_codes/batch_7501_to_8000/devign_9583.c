/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9583
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static void t_gen_mulu(TCGv d, TCGv d2, TCGv a, TCGv b)

{

	TCGv t0, t1;



	t0 = tcg_temp_new(TCG_TYPE_I64);

	t1 = tcg_temp_new(TCG_TYPE_I64);



	tcg_gen_extu_i32_i64(t0, a);

	tcg_gen_extu_i32_i64(t1, b);

	tcg_gen_mul_i64(t0, t0, t1);



	tcg_gen_trunc_i64_i32(d, t0);

	tcg_gen_shri_i64(t0, t0, 32);

	tcg_gen_trunc_i64_i32(d2, t0);



	tcg_temp_free(t0);

	tcg_temp_free(t1);

}
