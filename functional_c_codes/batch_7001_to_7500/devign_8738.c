/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8738
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42a268c241183877192c376d03bd9b6d527407c7
 */

static void dec10_reg_scc(DisasContext *dc)

{

    int cond = dc->dst;



    LOG_DIS("s%s $r%u\n", cc_name(cond), dc->src);



    if (cond != CC_A)

    {

        int l1;



        gen_tst_cc (dc, cpu_R[dc->src], cond);

        l1 = gen_new_label();

        tcg_gen_brcondi_tl(TCG_COND_EQ, cpu_R[dc->src], 0, l1);

        tcg_gen_movi_tl(cpu_R[dc->src], 1);

        gen_set_label(l1);

    } else {

        tcg_gen_movi_tl(cpu_R[dc->src], 1);

    }



    cris_cc_mask(dc, 0);

}
