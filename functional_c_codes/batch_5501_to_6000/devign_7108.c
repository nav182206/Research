/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7108
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c5a49c63fa26e8825ad101dfe86339ae4c216539
 */

static void spr_read_tbl(DisasContext *ctx, int gprn, int sprn)

{

    if (ctx->tb->cflags & CF_USE_ICOUNT) {

        gen_io_start();

    }

    gen_helper_load_tbl(cpu_gpr[gprn], cpu_env);

    if (ctx->tb->cflags & CF_USE_ICOUNT) {

        gen_io_end();

        gen_stop_exception(ctx);

    }

}
