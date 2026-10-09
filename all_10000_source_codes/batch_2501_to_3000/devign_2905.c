/* 
 * Benchmark Sample ID : devign_2905
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static void neon_store_reg(int reg, int pass, TCGv var)

{

    tcg_gen_st_i32(var, cpu_env, neon_reg_offset(reg, pass));

    dead_tmp(var);

}
