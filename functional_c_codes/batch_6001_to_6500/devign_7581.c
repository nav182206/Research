/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7581
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3604a76fea6ff37738d4a8f596be38407be74a83
 */

static void dec_sru(DisasContext *dc)

{

    if (dc->format == OP_FMT_RI) {

        LOG_DIS("srui r%d, r%d, %d\n", dc->r1, dc->r0, dc->imm5);

    } else {

        LOG_DIS("sru r%d, r%d, r%d\n", dc->r2, dc->r0, dc->r1);

    }



    if (!(dc->env->features & LM32_FEATURE_SHIFT)) {

        if (dc->format == OP_FMT_RI) {

            /* TODO: check r1 == 1 during runtime */

        } else {

            if (dc->imm5 != 1) {

                cpu_abort(dc->env, "hardware shifter is not available\n");

            }

        }

    }



    if (dc->format == OP_FMT_RI) {

        tcg_gen_shri_tl(cpu_R[dc->r1], cpu_R[dc->r0], dc->imm5);

    } else {

        TCGv t0 = tcg_temp_new();

        tcg_gen_andi_tl(t0, cpu_R[dc->r1], 0x1f);

        tcg_gen_shr_tl(cpu_R[dc->r2], cpu_R[dc->r0], t0);

        tcg_temp_free(t0);

    }

}
