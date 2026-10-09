/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9394
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=879c28133dfa54b780dffbb29e4dcfc6581f6281
 */

static int local_symlink(FsContext *ctx, const char *oldpath,

                            const char *newpath)

{

    return symlink(oldpath, rpath(ctx, newpath));

}
