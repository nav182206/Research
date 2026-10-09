/* 
 * Benchmark Sample ID : devign_5708
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=00ec5c37601accb2b85b089d72fc7ddff2f4222e
 */

static int v9fs_do_mkdir(V9fsState *s, V9fsString *path, mode_t mode)

{

    return s->ops->mkdir(&s->ctx, path->data, mode);

}
