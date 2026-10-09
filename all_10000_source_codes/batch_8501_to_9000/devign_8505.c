/* 
 * Benchmark Sample ID : devign_8505
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3d948cdf3760b52238038626a7ffa7d30913060b
 */

void qmp_block_job_cancel(const char *device,

                          bool has_force, bool force, Error **errp)

{

    BlockJob *job = find_block_job(device);



    if (!has_force) {

        force = false;

    }



    if (!job) {

        error_set(errp, QERR_BLOCK_JOB_NOT_ACTIVE, device);

        return;

    }

    if (job->paused && !force) {

        error_setg(errp, "The block job for device '%s' is currently paused",

                   device);

        return;

    }



    trace_qmp_block_job_cancel(job);

    block_job_cancel(job);

}
