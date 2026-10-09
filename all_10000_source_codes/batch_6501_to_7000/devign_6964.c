/* 
 * Benchmark Sample ID : devign_6964
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9224450208e0de62323b64ace91f98bc31d6e2c
 */

static void gen_cop1_ldst(DisasContext *ctx, uint32_t op, int rt,

                          int rs, int16_t imm)

{

    if (ctx->CP0_Config1 & (1 << CP0C1_FP)) {

        check_cp1_enabled(ctx);

        gen_flt_ldst(ctx, op, rt, rs, imm);

    } else {

        generate_exception_err(ctx, EXCP_CpU, 1);

    }

}
