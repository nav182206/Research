/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_991
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static ssize_t v9fs_synth_lgetxattr(FsContext *ctx, V9fsPath *path,

                                    const char *name, void *value, size_t size)

{

    errno = ENOTSUP;

    return -1;

}
