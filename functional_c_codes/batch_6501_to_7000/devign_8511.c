/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8511
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2d40564aaab3a99fe6ce00fc0fc893c02e9443ec
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

        if ((fs_ctx->export_flags & V9FS_SEC_MASK) != V9FS_SM_NONE) {

            return -1;

        }

    }

    return 0;

}
