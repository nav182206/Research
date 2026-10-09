/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8563
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b2fadda3e0196ffd485adde4fe9cdd6fae35300
 */

static void gen_mfdcr(DisasContext *ctx)

{

#if defined(CONFIG_USER_ONLY)

    gen_inval_exception(ctx, POWERPC_EXCP_PRIV_REG);

#else

    TCGv dcrn;

    if (unlikely(ctx->pr)) {

        gen_inval_exception(ctx, POWERPC_EXCP_PRIV_REG);

        return;

    }

    /* NIP cannot be restored if the memory exception comes from an helper */

    gen_update_nip(ctx, ctx->nip - 4);

    dcrn = tcg_const_tl(SPR(ctx->opcode));

    gen_helper_load_dcr(cpu_gpr[rD(ctx->opcode)], cpu_env, dcrn);

    tcg_temp_free(dcrn);

#endif

}
