/* 
 * Benchmark Sample ID : devign_383
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4ef130fca87b7a8c77e1af9ca967f28b683811d7
 */

static int img_open_password(BlockBackend *blk, const char *filename,

                             int flags, bool quiet)

{

    BlockDriverState *bs;

    char password[256];



    bs = blk_bs(blk);

    if (bdrv_is_encrypted(bs) && !(flags & BDRV_O_NO_IO)) {

        qprintf(quiet, "Disk image '%s' is encrypted.\n", filename);

        if (qemu_read_password(password, sizeof(password)) < 0) {

            error_report("No password given");

            return -1;

        }

        if (bdrv_set_key(bs, password) < 0) {

            error_report("invalid password");

            return -1;

        }

    }

    return 0;

}
