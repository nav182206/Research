/* 
 * Benchmark Sample ID : devign_5277
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b2fadda3e0196ffd485adde4fe9cdd6fae35300
 */

static void gen_rac(DisasContext *ctx)

{

#if defined(CONFIG_USER_ONLY)

    gen_inval_exception(ctx, POWERPC_EXCP_PRIV_OPC);

#else

    TCGv t0;

    if (unlikely(ctx->pr)) {

        gen_inval_exception(ctx, POWERPC_EXCP_PRIV_OPC);

        return;

    }

    t0 = tcg_temp_new();

    gen_addr_reg_index(ctx, t0);

    gen_helper_rac(cpu_gpr[rD(ctx->opcode)], cpu_env, t0);

    tcg_temp_free(t0);

#endif

}
