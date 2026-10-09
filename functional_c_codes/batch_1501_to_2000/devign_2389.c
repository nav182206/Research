/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2389
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static int v9fs_synth_rename(FsContext *ctx, const char *oldpath,

                             const char *newpath)

{

    errno = EPERM;

    return -1;

}
