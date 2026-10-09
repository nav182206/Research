/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2509
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42a268c241183877192c376d03bd9b6d527407c7
 */

static void disas_cond_select(DisasContext *s, uint32_t insn)

{

    unsigned int sf, else_inv, rm, cond, else_inc, rn, rd;

    TCGv_i64 tcg_rd, tcg_src;



    if (extract32(insn, 29, 1) || extract32(insn, 11, 1)) {

        /* S == 1 or op2<1> == 1 */

        unallocated_encoding(s);

        return;

    }

    sf = extract32(insn, 31, 1);

    else_inv = extract32(insn, 30, 1);

    rm = extract32(insn, 16, 5);

    cond = extract32(insn, 12, 4);

    else_inc = extract32(insn, 10, 1);

    rn = extract32(insn, 5, 5);

    rd = extract32(insn, 0, 5);



    if (rd == 31) {

        /* silly no-op write; until we use movcond we must special-case

         * this to avoid a dead temporary across basic blocks.

         */

        return;

    }



    tcg_rd = cpu_reg(s, rd);



    if (cond >= 0x0e) { /* condition "always" */

        tcg_src = read_cpu_reg(s, rn, sf);

        tcg_gen_mov_i64(tcg_rd, tcg_src);

    } else {

        /* OPTME: we could use movcond here, at the cost of duplicating

         * a lot of the arm_gen_test_cc() logic.

         */

        int label_match = gen_new_label();

        int label_continue = gen_new_label();



        arm_gen_test_cc(cond, label_match);

        /* nomatch: */

        tcg_src = cpu_reg(s, rm);



        if (else_inv && else_inc) {

            tcg_gen_neg_i64(tcg_rd, tcg_src);

        } else if (else_inv) {

            tcg_gen_not_i64(tcg_rd, tcg_src);

        } else if (else_inc) {

            tcg_gen_addi_i64(tcg_rd, tcg_src, 1);

        } else {

            tcg_gen_mov_i64(tcg_rd, tcg_src);

        }

        if (!sf) {

            tcg_gen_ext32u_i64(tcg_rd, tcg_rd);

        }

        tcg_gen_br(label_continue);

        /* match: */

        gen_set_label(label_match);

        tcg_src = read_cpu_reg(s, rn, sf);

        tcg_gen_mov_i64(tcg_rd, tcg_src);

        /* continue: */

        gen_set_label(label_continue);

    }

}
