/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5808
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=794f01414f9f4c4d0c6f1961154674961941c197
 */

static int block_job_finish_sync(BlockJob *job,

                                 void (*finish)(BlockJob *, Error **errp),

                                 Error **errp)

{

    BlockDriverState *bs = job->bs;

    Error *local_err = NULL;

    int ret;



    assert(bs->job == job);



    block_job_ref(job);

    finish(job, &local_err);

    if (local_err) {

        error_propagate(errp, local_err);

        block_job_unref(job);

        return -EBUSY;

    }

    while (!job->completed) {

        aio_poll(bdrv_get_aio_context(bs), true);

    }

    ret = (job->cancelled && job->ret == 0) ? -ECANCELED : job->ret;

    block_job_unref(job);

    return ret;

}
