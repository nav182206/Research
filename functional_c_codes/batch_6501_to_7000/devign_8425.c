/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8425
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=27a69bb088bee6d4efea254659422fb9c751b3c7
 */

static inline void gen_evmergelohi(DisasContext *ctx)

{

    if (unlikely(!ctx->spe_enabled)) {

        gen_exception(ctx, POWERPC_EXCP_APU);

        return;

    }

#if defined(TARGET_PPC64)

    TCGv t0 = tcg_temp_new();

    TCGv t1 = tcg_temp_new();

    tcg_gen_shri_tl(t0, cpu_gpr[rB(ctx->opcode)], 32);

    tcg_gen_shli_tl(t1, cpu_gpr[rA(ctx->opcode)], 32);

    tcg_gen_or_tl(cpu_gpr[rD(ctx->opcode)], t0, t1);

    tcg_temp_free(t0);

    tcg_temp_free(t1);

#else

    if (rD(ctx->opcode) == rA(ctx->opcode)) {

        TCGv_i32 tmp = tcg_temp_new_i32();

        tcg_gen_mov_i32(tmp, cpu_gpr[rA(ctx->opcode)]);

        tcg_gen_mov_i32(cpu_gpr[rD(ctx->opcode)], cpu_gprh[rB(ctx->opcode)]);

        tcg_gen_mov_i32(cpu_gprh[rD(ctx->opcode)], tmp);

        tcg_temp_free_i32(tmp);

    } else {

        tcg_gen_mov_i32(cpu_gpr[rD(ctx->opcode)], cpu_gprh[rB(ctx->opcode)]);

        tcg_gen_mov_i32(cpu_gprh[rD(ctx->opcode)], cpu_gpr[rA(ctx->opcode)]);

    }

#endif

}
