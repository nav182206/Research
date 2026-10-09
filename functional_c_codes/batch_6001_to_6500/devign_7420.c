/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7420
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_lsetxattr(FsContext *ctx, V9fsPath *fs_path, const char *name,

                           void *value, size_t size, int flags)

{

    int retval;

    V9fsString xname, xvalue;



    v9fs_string_init(&xname);

    v9fs_string_sprintf(&xname, "%s", name);



    v9fs_string_init(&xvalue);

    xvalue.size = size;

    xvalue.data = g_malloc(size);

    memcpy(xvalue.data, value, size);



    retval = v9fs_request(ctx->private, T_LSETXATTR, value, "sssdd",

                          fs_path, &xname, &xvalue, size, flags);

    v9fs_string_free(&xname);

    v9fs_string_free(&xvalue);

    if (retval < 0) {

        errno = -retval;

    }

    return retval;

}
