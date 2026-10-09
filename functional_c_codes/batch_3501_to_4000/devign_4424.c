/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4424
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eb05e011e248c6fb6baee295e14fd206e136028c
 */

static void block_job_defer_to_main_loop_bh(void *opaque)

{

    BlockJobDeferToMainLoopData *data = opaque;

    AioContext *aio_context;



    /* Prevent race with block_job_defer_to_main_loop() */

    aio_context_acquire(data->aio_context);



    /* Fetch BDS AioContext again, in case it has changed */

    aio_context = blk_get_aio_context(data->job->blk);

    if (aio_context != data->aio_context) {

        aio_context_acquire(aio_context);

    }



    data->job->deferred_to_main_loop = false;

    data->fn(data->job, data->opaque);



    if (aio_context != data->aio_context) {

        aio_context_release(aio_context);

    }



    aio_context_release(data->aio_context);



    g_free(data);

}
