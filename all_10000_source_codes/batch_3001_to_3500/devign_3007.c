/* 
 * Benchmark Sample ID : devign_3007
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a076972a4d36381d610a854f0c336507650a1d34
 */

aio_ctx_finalize(GSource     *source)
{
    AioContext *ctx = (AioContext *) source;
    thread_pool_free(ctx->thread_pool);
    aio_set_event_notifier(ctx, &ctx->notifier, NULL);
    event_notifier_cleanup(&ctx->notifier);
    rfifolock_destroy(&ctx->lock);
    qemu_mutex_destroy(&ctx->bh_lock);
    timerlistgroup_deinit(&ctx->tlg);
