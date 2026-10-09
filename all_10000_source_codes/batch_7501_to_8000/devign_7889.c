/* 
 * Benchmark Sample ID : devign_7889
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static TCGv neon_load_reg(int reg, int pass)

{

    TCGv tmp = new_tmp();

    tcg_gen_ld_i32(tmp, cpu_env, neon_reg_offset(reg, pass));

    return tmp;

}
