/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9706
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=56ad3e54dad6cdcee8668d170df161d89581846f
 */

static ssize_t mp_pacl_getxattr(FsContext *ctx, const char *path,

                                const char *name, void *value, size_t size)

{

    char *buffer;

    ssize_t ret;



    buffer = rpath(ctx, path);

    ret = lgetxattr(buffer, MAP_ACL_ACCESS, value, size);

    g_free(buffer);

    return ret;

}
