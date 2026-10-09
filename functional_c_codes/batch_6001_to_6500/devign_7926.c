/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7926
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=751ebd76e654bd1e65da08ecf694325282b4cfcc
 */

BlockJobInfo *block_job_query(BlockJob *job)

{

    BlockJobInfo *info = g_new0(BlockJobInfo, 1);

    info->type      = g_strdup(BlockJobType_lookup[job->driver->job_type]);

    info->device    = g_strdup(bdrv_get_device_name(job->bs));

    info->len       = job->len;

    info->busy      = job->busy;

    info->paused    = job->paused;

    info->offset    = job->offset;

    info->speed     = job->speed;

    info->io_status = job->iostatus;

    info->ready     = job->ready;

    return info;

}
