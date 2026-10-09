/* 
 * Benchmark Sample ID : devign_5255
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b2fadda3e0196ffd485adde4fe9cdd6fae35300
 */

static void gen_tlbilx_booke206(DisasContext *ctx)

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



    switch((ctx->opcode >> 21) & 0x3) {

    case 0:

        gen_helper_booke206_tlbilx0(cpu_env, t0);

        break;

    case 1:

        gen_helper_booke206_tlbilx1(cpu_env, t0);

        break;

    case 3:

        gen_helper_booke206_tlbilx3(cpu_env, t0);

        break;

    default:

        gen_inval_exception(ctx, POWERPC_EXCP_INVAL_INVAL);

        break;

    }



    tcg_temp_free(t0);

#endif

}
