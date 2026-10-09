/* 
 * Benchmark Sample ID : devign_1685
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static void v9fs_synth_seekdir(FsContext *ctx, V9fsFidOpenState *fs, off_t off)

{

    V9fsSynthOpenState *synth_open = fs->private;

    synth_open->offset = off;

}
