/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7204
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

void aio_context_set_poll_params(AioContext *ctx, int64_t max_ns,

                                 int64_t grow, int64_t shrink, Error **errp)

{

    /* No thread synchronization here, it doesn't matter if an incorrect value

     * is used once.

     */

    ctx->poll_max_ns = max_ns;

    ctx->poll_ns = 0;

    ctx->poll_grow = grow;

    ctx->poll_shrink = shrink;



    aio_notify(ctx);

}
