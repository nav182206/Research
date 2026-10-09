/* 
 * Benchmark Sample ID : devign_6727
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static int v9fs_synth_chown(FsContext *fs_ctx, V9fsPath *path, FsCred *credp)

{

    errno = EPERM;

    return -1;

}
