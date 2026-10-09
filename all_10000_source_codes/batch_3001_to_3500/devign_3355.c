/* 
 * Benchmark Sample ID : devign_3355
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bae8196d9f97916de6323e70e3e374362ee16ec4
 */

static AioContext *block_job_get_aio_context(BlockJob *job)

{

    return job->deferred_to_main_loop ?

           qemu_get_aio_context() :

           blk_get_aio_context(job->blk);

}
