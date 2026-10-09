/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3666
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eb05e011e248c6fb6baee295e14fd206e136028c
 */

void block_job_enter(BlockJob *job)

{

    if (job->co && !job->busy) {

        bdrv_coroutine_enter(blk_bs(job->blk), job->co);

    }

}
