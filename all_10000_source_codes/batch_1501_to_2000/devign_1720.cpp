/* 
 * Benchmark Sample ID : devign_1720
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=72f0d0bf51362011c4d841a89fb8f5cfb16e0bf3
 */

static int mp_dacl_removexattr(FsContext *ctx,

                               const char *path, const char *name)

{

    int ret;

    char *buffer;



    buffer = rpath(ctx, path);

    ret  = lremovexattr(buffer, MAP_ACL_DEFAULT);

    if (ret == -1 && errno == ENODATA) {

        /*

         * We don't get ENODATA error when trying to remove a

         * posix acl that is not present. So don't throw the error

         * even in case of mapped security model

         */

        errno = 0;

        ret = 0;

    }

    g_free(buffer);

    return ret;

}
