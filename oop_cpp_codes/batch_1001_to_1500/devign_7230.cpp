/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7230
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static int v9fs_synth_readdir_r(FsContext *ctx, V9fsFidOpenState *fs,

                                struct dirent *entry, struct dirent **result)

{

    int ret;

    V9fsSynthOpenState *synth_open = fs->private;

    V9fsSynthNode *node = synth_open->node;

    ret = v9fs_synth_get_dentry(node, entry, result, synth_open->offset);

    if (!ret && *result != NULL) {

        synth_open->offset++;

    }

    return ret;

}
