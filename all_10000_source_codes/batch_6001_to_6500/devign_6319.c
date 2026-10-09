/* 
 * Benchmark Sample ID : devign_6319
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fc22118d9bb56ec71655b936a29513c140e6c289
 */

static int local_lremovexattr(FsContext *ctx,

                              const char *path, const char *name)

{

    if ((ctx->fs_sm == SM_MAPPED) &&

        (strncmp(name, "user.virtfs.", 12) == 0)) {

        /*

         * Don't allow fetch of user.virtfs namesapce

         * in case of mapped security

         */

        errno = EACCES;

        return -1;

    }

    return lremovexattr(rpath(ctx, path), name);

}
