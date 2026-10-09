/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4979
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_lremovexattr(FsContext *ctx, V9fsPath *fs_path,

                              const char *name)

{

    int retval;

    V9fsString xname;



    v9fs_string_init(&xname);

    v9fs_string_sprintf(&xname, "%s", name);

    retval = v9fs_request(ctx->private, T_LREMOVEXATTR, NULL, "ss",

                          fs_path, &xname);

    v9fs_string_free(&xname);

    if (retval < 0) {

        errno = -retval;

    }

    return retval;

}
