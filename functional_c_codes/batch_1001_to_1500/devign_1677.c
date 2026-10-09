/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1677
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42a268c241183877192c376d03bd9b6d527407c7
 */

static void gen_brcond(DisasContext *dc, TCGCond cond,

        TCGv_i32 t0, TCGv_i32 t1, uint32_t offset)

{

    int label = gen_new_label();



    gen_advance_ccount(dc);

    tcg_gen_brcond_i32(cond, t0, t1, label);

    gen_jumpi_check_loop_end(dc, 0);

    gen_set_label(label);

    gen_jumpi(dc, dc->pc + offset, 1);

}
