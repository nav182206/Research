/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7747
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4fa4ce7107c6ec432f185307158c5df91ce54308
 */

static int mp_pacl_setxattr(FsContext *ctx, const char *path, const char *name,

                            void *value, size_t size, int flags)

{

    char buffer[PATH_MAX];

    return lsetxattr(rpath(ctx, path, buffer), MAP_ACL_ACCESS, value,

            size, flags);

}
