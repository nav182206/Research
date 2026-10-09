/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_388
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b2fadda3e0196ffd485adde4fe9cdd6fae35300
 */

static void gen_tlbre_440(DisasContext *ctx)

{

#if defined(CONFIG_USER_ONLY)

    gen_inval_exception(ctx, POWERPC_EXCP_PRIV_OPC);

#else

    if (unlikely(ctx->pr)) {

        gen_inval_exception(ctx, POWERPC_EXCP_PRIV_OPC);

        return;

    }

    switch (rB(ctx->opcode)) {

    case 0:

    case 1:

    case 2:

        {

            TCGv_i32 t0 = tcg_const_i32(rB(ctx->opcode));

            gen_helper_440_tlbre(cpu_gpr[rD(ctx->opcode)], cpu_env,

                                 t0, cpu_gpr[rA(ctx->opcode)]);

            tcg_temp_free_i32(t0);

        }

        break;

    default:

        gen_inval_exception(ctx, POWERPC_EXCP_INVAL_INVAL);

        break;

    }

#endif

}
