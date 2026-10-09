/* 
 * Benchmark Sample ID : devign_1194
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e41029b378b4a65a0b89b5a8dc087aca6b5d012d
 */

static void gen_dstst(DisasContext *ctx)

{

    if (rA(ctx->opcode) == 0) {

        gen_inval_exception(ctx, POWERPC_EXCP_INVAL_LSWX);

    } else {

        /* interpreted as no-op */

    }



}
