/* 
 * Benchmark Sample ID : devign_6762
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=56ad3e54dad6cdcee8668d170df161d89581846f
 */

static ssize_t mp_user_getxattr(FsContext *ctx, const char *path,

                                const char *name, void *value, size_t size)

{

    char *buffer;

    ssize_t ret;



    if (strncmp(name, "user.virtfs.", 12) == 0) {

        /*

         * Don't allow fetch of user.virtfs namesapce

         * in case of mapped security

         */

        errno = ENOATTR;

        return -1;

    }

    buffer = rpath(ctx, path);

    ret = lgetxattr(buffer, name, value, size);

    g_free(buffer);

    return ret;

}
