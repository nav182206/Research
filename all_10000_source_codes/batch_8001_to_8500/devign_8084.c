/* 
 * Benchmark Sample ID : devign_8084
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=27a69bb088bee6d4efea254659422fb9c751b3c7
 */

static inline void gen_efsneg(DisasContext *ctx)

{

    if (unlikely(!ctx->spe_enabled)) {

        gen_exception(ctx, POWERPC_EXCP_APU);

        return;

    }

    tcg_gen_xori_tl(cpu_gpr[rD(ctx->opcode)], cpu_gpr[rA(ctx->opcode)], 0x80000000);

}
