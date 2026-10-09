/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3160
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=697ab892786d47008807a49f57b2fd86adfcd098
 */

static void gen_b(DisasContext *ctx)

{

    target_ulong li, target;



    ctx->exception = POWERPC_EXCP_BRANCH;

    /* sign extend LI */

#if defined(TARGET_PPC64)

    if (ctx->sf_mode)

        li = ((int64_t)LI(ctx->opcode) << 38) >> 38;

    else

#endif

        li = ((int32_t)LI(ctx->opcode) << 6) >> 6;

    if (likely(AA(ctx->opcode) == 0))

        target = ctx->nip + li - 4;

    else

        target = li;

    if (LK(ctx->opcode))

        gen_setlr(ctx, ctx->nip);


    gen_goto_tb(ctx, 0, target);

}
