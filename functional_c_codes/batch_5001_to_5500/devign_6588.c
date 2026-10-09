/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6588
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b2fadda3e0196ffd485adde4fe9cdd6fae35300
 */

static void gen_mfsr_64b(DisasContext *ctx)

{

#if defined(CONFIG_USER_ONLY)

    gen_inval_exception(ctx, POWERPC_EXCP_PRIV_REG);

#else

    TCGv t0;

    if (unlikely(ctx->pr)) {

        gen_inval_exception(ctx, POWERPC_EXCP_PRIV_REG);

        return;

    }

    t0 = tcg_const_tl(SR(ctx->opcode));

    gen_helper_load_sr(cpu_gpr[rD(ctx->opcode)], cpu_env, t0);

    tcg_temp_free(t0);

#endif

}
