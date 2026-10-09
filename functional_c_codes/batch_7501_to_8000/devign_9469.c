/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9469
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fc22118d9bb56ec71655b936a29513c140e6c289
 */

static ssize_t local_lgetxattr(FsContext *ctx, const char *path,

                               const char *name, void *value, size_t size)

{

    if ((ctx->fs_sm == SM_MAPPED) &&

        (strncmp(name, "user.virtfs.", 12) == 0)) {

        /*

         * Don't allow fetch of user.virtfs namesapce

         * in case of mapped security

         */

        errno = ENOATTR;

        return -1;

    }



    return lgetxattr(rpath(ctx, path), name, value, size);

}
