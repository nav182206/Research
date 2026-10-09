/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9167
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4c241cf5d6ca06c682e033cf8b327b63b1f4b784
 */

void block_job_user_resume(BlockJob *job)

{

    if (job && job->user_paused && job->pause_count > 0) {

        job->user_paused = false;

        block_job_iostatus_reset(job);

        block_job_resume(job);

    }

}
