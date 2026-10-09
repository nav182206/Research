/* 
 * Benchmark Sample ID : devign_7195
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a193b0f0a8d7735f4eb2ff863fd0902a5fa5eec6
 */

void backup_do_checkpoint(BlockJob *job, Error **errp)

{

    BackupBlockJob *backup_job = container_of(job, BackupBlockJob, common);

    int64_t len;



    assert(job->driver->job_type == BLOCK_JOB_TYPE_BACKUP);



    if (backup_job->sync_mode != MIRROR_SYNC_MODE_NONE) {

        error_setg(errp, "The backup job only supports block checkpoint in"

                   " sync=none mode");

        return;

    }



    len = DIV_ROUND_UP(backup_job->common.len, backup_job->cluster_size);

    bitmap_zero(backup_job->done_bitmap, len);

}
