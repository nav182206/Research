/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6424
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4750a96f6baf8949cc04a0c5b7167606544a4401
 */

static int v9fs_do_open2(V9fsState *s, V9fsString *path, int flags, mode_t mode)

{

    return s->ops->open2(&s->ctx, path->data, flags, mode);

}
