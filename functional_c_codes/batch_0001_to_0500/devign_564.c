/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_564
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static TCGv_i64 gen_subq_msw(TCGv_i64 a, TCGv b)

{

    TCGv_i64 tmp64 = tcg_temp_new_i64();



    tcg_gen_extu_i32_i64(tmp64, b);

    dead_tmp(b);

    tcg_gen_shli_i64(tmp64, tmp64, 32);

    tcg_gen_sub_i64(a, tmp64, a);



    tcg_temp_free_i64(tmp64);

    return a;

}
