/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_628
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b68e60e6f0d2865e961a800fb8db96a7fc6494c4
 */

static void gen_ori(DisasContext *ctx)

{

    target_ulong uimm = UIMM(ctx->opcode);



    if (rS(ctx->opcode) == rA(ctx->opcode) && uimm == 0) {

        /* NOP */

        /* XXX: should handle special NOPs for POWER series */

        return;

    }

    tcg_gen_ori_tl(cpu_gpr[rA(ctx->opcode)], cpu_gpr[rS(ctx->opcode)], uimm);

}
