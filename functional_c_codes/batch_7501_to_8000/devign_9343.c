/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9343
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4750a96f6baf8949cc04a0c5b7167606544a4401
 */

static int local_open2(FsContext *ctx, const char *path, int flags, mode_t mode)

{

    return open(rpath(ctx, path), flags, mode);

}
