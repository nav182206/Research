/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6875
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static int v9fs_synth_link(FsContext *fs_ctx, V9fsPath *oldpath,

                           V9fsPath *newpath, const char *buf)

{

    errno = EPERM;

    return -1;

}
