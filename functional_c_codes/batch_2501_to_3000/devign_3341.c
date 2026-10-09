/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3341
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static void gen_neon_dup_u8(TCGv var, int shift)

{

    TCGv tmp = new_tmp();

    if (shift)

        tcg_gen_shri_i32(var, var, shift);

    tcg_gen_ext8u_i32(var, var);

    tcg_gen_shli_i32(tmp, var, 8);

    tcg_gen_or_i32(var, var, tmp);

    tcg_gen_shli_i32(tmp, var, 16);

    tcg_gen_or_i32(var, var, tmp);

    dead_tmp(tmp);

}
