/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7501
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bec93d7283b635aabaf0bbff67b6da7fc99e020a
 */

static void gen_compute_eflags_z(DisasContext *s, TCGv reg, bool inv)

{

    switch (s->cc_op) {

    case CC_OP_DYNAMIC:

        gen_compute_eflags(s);

        /* FALLTHRU */

    case CC_OP_EFLAGS:

        tcg_gen_shri_tl(reg, cpu_cc_src, 6);

        tcg_gen_andi_tl(reg, reg, 1);

        if (inv) {

            tcg_gen_xori_tl(reg, reg, 1);

        }

        break;

    default:

        {

            int size = (s->cc_op - CC_OP_ADDB) & 3;

            TCGv t0 = gen_ext_tl(reg, cpu_cc_dst, size, false);

            tcg_gen_setcondi_tl(inv ? TCG_COND_NE : TCG_COND_EQ, reg, t0, 0);

        }

        break;

    }

}
