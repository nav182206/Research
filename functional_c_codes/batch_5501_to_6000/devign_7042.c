/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7042
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=90e496386fe7fd32c189561f846b7913f95b8cf4
 */

static TCGv_i32 read_fp_sreg(DisasContext *s, int reg)

{

    TCGv_i32 v = tcg_temp_new_i32();



    tcg_gen_ld_i32(v, cpu_env, fp_reg_offset(reg, MO_32));

    return v;

}
