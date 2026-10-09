/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8213
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static int v9fs_synth_renameat(FsContext *ctx, V9fsPath *olddir,

                               const char *old_name, V9fsPath *newdir,

                               const char *new_name)

{

    errno = EPERM;

    return -1;

}
