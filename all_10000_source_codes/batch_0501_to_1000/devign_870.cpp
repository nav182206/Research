/* 
 * Benchmark Sample ID : devign_870
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

aio_ctx_finalize(GSource     *source)

{

    AioContext *ctx = (AioContext *) source;



    thread_pool_free(ctx->thread_pool);



#ifdef CONFIG_LINUX_AIO

    if (ctx->linux_aio) {

        laio_detach_aio_context(ctx->linux_aio, ctx);

        laio_cleanup(ctx->linux_aio);

        ctx->linux_aio = NULL;

    }

#endif



    qemu_lockcnt_lock(&ctx->list_lock);

    assert(!qemu_lockcnt_count(&ctx->list_lock));

    while (ctx->first_bh) {

        QEMUBH *next = ctx->first_bh->next;



        /* qemu_bh_delete() must have been called on BHs in this AioContext */

        assert(ctx->first_bh->deleted);



        g_free(ctx->first_bh);

        ctx->first_bh = next;

    }

    qemu_lockcnt_unlock(&ctx->list_lock);



    aio_set_event_notifier(ctx, &ctx->notifier, false, NULL, NULL);

    event_notifier_cleanup(&ctx->notifier);

    qemu_rec_mutex_destroy(&ctx->lock);

    qemu_lockcnt_destroy(&ctx->list_lock);

    timerlistgroup_deinit(&ctx->tlg);

}
