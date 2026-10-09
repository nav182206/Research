/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9881
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=364031f17932814484657e5551ba12957d993d7e
 */

static int v9fs_synth_open(FsContext *ctx, V9fsPath *fs_path,

                           int flags, V9fsFidOpenState *fs)

{

    V9fsSynthOpenState *synth_open;

    V9fsSynthNode *node = *(V9fsSynthNode **)fs_path->data;



    synth_open = g_malloc(sizeof(*synth_open));

    synth_open->node = node;

    node->open_count++;

    fs->private = synth_open;

    return 0;

}
