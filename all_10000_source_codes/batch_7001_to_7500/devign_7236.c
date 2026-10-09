/* 
 * Benchmark Sample ID : devign_7236
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static void gen_addq(DisasContext *s, TCGv val, int rlow, int rhigh)

{

    TCGv tmp;

    TCGv tmpl;

    TCGv tmph;



    /* Load 64-bit value rd:rn.  */

    tmpl = load_reg(s, rlow);

    tmph = load_reg(s, rhigh);

    tmp = tcg_temp_new(TCG_TYPE_I64);

    tcg_gen_concat_i32_i64(tmp, tmpl, tmph);

    dead_tmp(tmpl);

    dead_tmp(tmph);

    tcg_gen_add_i64(val, val, tmp);

}
