/* 
 * Benchmark Sample ID : devign_7877
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static off_t v9fs_synth_telldir(FsContext *ctx, V9fsFidOpenState *fs)

{

    V9fsSynthOpenState *synth_open = fs->private;

    return synth_open->offset;

}
