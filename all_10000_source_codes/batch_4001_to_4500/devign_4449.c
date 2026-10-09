/* 
 * Benchmark Sample ID : devign_4449
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c5a49c63fa26e8825ad101dfe86339ae4c216539
 */

static void spr_write_hdecr(DisasContext *ctx, int sprn, int gprn)

{

    if (ctx->tb->cflags & CF_USE_ICOUNT) {

        gen_io_start();

    }

    gen_helper_store_hdecr(cpu_env, cpu_gpr[gprn]);

    if (ctx->tb->cflags & CF_USE_ICOUNT) {

        gen_io_end();

        gen_stop_exception(ctx);

    }

}
