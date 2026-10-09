/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5722
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b97400caef60ccfb0bc81c59f8bd824c43a0d6c8
 */

static int local_post_create_passthrough(FsContext *fs_ctx, const char *path,

                                         FsCred *credp)

{

    char buffer[PATH_MAX];



    if (chmod(rpath(fs_ctx, path, buffer), credp->fc_mode & 07777) < 0) {

        return -1;

    }

    if (lchown(rpath(fs_ctx, path, buffer), credp->fc_uid,

                credp->fc_gid) < 0) {

        /*

         * If we fail to change ownership and if we are

         * using security model none. Ignore the error

         */

        if (fs_ctx->fs_sm != SM_NONE) {

            return -1;

        }

    }

    return 0;

}
