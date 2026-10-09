/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3171
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=31ca6d077c24b7aaa322d8930e3e5debbdb4a047
 */

static void mirror_complete(BlockJob *job, Error **errp)

{

    MirrorBlockJob *s = container_of(job, MirrorBlockJob, common);

    int ret;



    ret = bdrv_open_backing_file(s->target);

    if (ret < 0) {

        char backing_filename[PATH_MAX];

        bdrv_get_full_backing_filename(s->target, backing_filename,

                                       sizeof(backing_filename));

        error_set(errp, QERR_OPEN_FILE_FAILED, backing_filename);

        return;

    }

    if (!s->synced) {

        error_set(errp, QERR_BLOCK_JOB_NOT_READY, job->bs->device_name);

        return;

    }



    s->should_complete = true;

    block_job_resume(job);

}
