/* 
 * Benchmark Sample ID : devign_285
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=356f59b8757f47c0aca3e2e4e51d6010f64cade1
 */

void block_job_enter(BlockJob *job)

{

    if (!block_job_started(job)) {

        return;

    }

    if (job->deferred_to_main_loop) {

        return;

    }



    if (!job->busy) {

        bdrv_coroutine_enter(blk_bs(job->blk), job->co);

    }

}
