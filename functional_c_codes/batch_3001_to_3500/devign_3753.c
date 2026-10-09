/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3753
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static void v9fs_synth_rewinddir(FsContext *ctx, V9fsFidOpenState *fs)

{

    v9fs_synth_seekdir(ctx, fs, 0);

}
