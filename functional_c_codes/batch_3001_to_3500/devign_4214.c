/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4214
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_chown(FsContext *fs_ctx, V9fsPath *fs_path, FsCred *credp)

{

    int retval;

    retval = v9fs_request(fs_ctx->private, T_CHOWN, NULL, "sdd",

                          fs_path, credp->fc_uid, credp->fc_gid);

    if (retval < 0) {

        errno = -retval;

    }

    return retval;

}
