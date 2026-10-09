/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9678
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static void gen_imull(TCGv a, TCGv b)

{

    TCGv tmp1 = tcg_temp_new(TCG_TYPE_I64);

    TCGv tmp2 = tcg_temp_new(TCG_TYPE_I64);



    tcg_gen_ext_i32_i64(tmp1, a);

    tcg_gen_ext_i32_i64(tmp2, b);

    tcg_gen_mul_i64(tmp1, tmp1, tmp2);

    tcg_gen_trunc_i64_i32(a, tmp1);

    tcg_gen_shri_i64(tmp1, tmp1, 32);

    tcg_gen_trunc_i64_i32(b, tmp1);

}
