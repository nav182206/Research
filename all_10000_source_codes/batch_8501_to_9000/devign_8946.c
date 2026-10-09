/* 
 * Benchmark Sample ID : devign_8946
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_remove(FsContext *ctx, const char *path)

{

    int retval;

    V9fsString name;

    v9fs_string_init(&name);

    v9fs_string_sprintf(&name, "%s", path);

    retval = v9fs_request(ctx->private, T_REMOVE, NULL, "s", &name);

    v9fs_string_free(&name);

    if (retval < 0) {

        errno = -retval;

    }

    return retval;

}
