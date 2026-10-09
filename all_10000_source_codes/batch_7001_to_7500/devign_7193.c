/* 
 * Benchmark Sample ID : devign_7193
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_lstat(FsContext *fs_ctx, V9fsPath *fs_path, struct stat *stbuf)

{

    int retval;

    retval = v9fs_request(fs_ctx->private, T_LSTAT, stbuf, "s", fs_path);

    if (retval < 0) {

        errno = -retval;

        return -1;

    }

    return retval;

}
