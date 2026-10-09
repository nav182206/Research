/* 
 * Benchmark Sample ID : devign_885
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static int v9fs_synth_utimensat(FsContext *fs_ctx, V9fsPath *path,

                                const struct timespec *buf)

{

    errno = EPERM;

    return 0;

}
