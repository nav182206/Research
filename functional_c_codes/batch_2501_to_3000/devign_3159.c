/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3159
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e36aba757f76673007a80b3cd56a4062c2e3462
 */

int pt_setxattr(FsContext *ctx, const char *path, const char *name, void *value,

                size_t size, int flags)

{

    char *buffer;

    int ret;



    buffer = rpath(ctx, path);

    ret = lsetxattr(buffer, name, value, size, flags);

    g_free(buffer);

    return ret;

}
