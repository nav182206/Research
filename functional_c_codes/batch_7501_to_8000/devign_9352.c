/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9352
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3d948cdf3760b52238038626a7ffa7d30913060b
 */

void qmp_block_job_pause(const char *device, Error **errp)

{

    BlockJob *job = find_block_job(device);



    if (!job) {

        error_set(errp, QERR_BLOCK_JOB_NOT_ACTIVE, device);

        return;

    }



    trace_qmp_block_job_pause(job);

    block_job_pause(job);

}
