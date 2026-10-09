/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2243
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bae8196d9f97916de6323e70e3e374362ee16ec4
 */

static void block_job_detach_aio_context(void *opaque)

{

    BlockJob *job = opaque;



    /* In case the job terminates during aio_poll()... */

    block_job_ref(job);



    block_job_pause(job);



    if (!job->paused) {

        /* If job is !job->busy this kicks it into the next pause point. */

        block_job_enter(job);

    }

    while (!job->paused && !job->completed) {

        aio_poll(block_job_get_aio_context(job), true);

    }



    block_job_unref(job);

}
