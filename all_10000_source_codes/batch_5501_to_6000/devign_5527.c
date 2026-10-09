/* 
 * Benchmark Sample ID : devign_5527
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=751ebd76e654bd1e65da08ecf694325282b4cfcc
 */

void block_job_cancel(BlockJob *job)

{

    job->cancelled = true;

    block_job_resume(job);

}
