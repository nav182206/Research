/* 
 * Benchmark Sample ID : devign_355
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=356f59b8757f47c0aca3e2e4e51d6010f64cade1
 */

void block_job_yield(BlockJob *job)

{

    assert(job->busy);



    /* Check cancellation *before* setting busy = false, too!  */

    if (block_job_is_cancelled(job)) {

        return;

    }



    job->busy = false;

    if (!block_job_should_pause(job)) {

        qemu_coroutine_yield();

    }

    job->busy = true;



    block_job_pause_point(job);

}
