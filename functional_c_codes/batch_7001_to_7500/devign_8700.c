/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8700
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=111049a4ecefc9cf1ac75c773f4c5c165f27fe63
 */

static void drive_backup_abort(BlkActionState *common)

{

    DriveBackupState *state = DO_UPCAST(DriveBackupState, common, common);

    BlockDriverState *bs = state->bs;



    /* Only cancel if it's the job we started */

    if (bs && bs->job && bs->job == state->job) {

        block_job_cancel_sync(bs->job);

    }

}
