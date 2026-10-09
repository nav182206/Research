/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1321
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=879c28133dfa54b780dffbb29e4dcfc6581f6281
 */

static ssize_t local_readlink(FsContext *ctx, const char *path,

                                char *buf, size_t bufsz)

{

    return readlink(rpath(ctx, path), buf, bufsz);

}
