/* 
 * Benchmark Sample ID : devign_5432
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4fa4ce7107c6ec432f185307158c5df91ce54308
 */

static ssize_t mp_dacl_getxattr(FsContext *ctx, const char *path,

                                const char *name, void *value, size_t size)

{

    char buffer[PATH_MAX];

    return lgetxattr(rpath(ctx, path, buffer), MAP_ACL_DEFAULT, value, size);

}
