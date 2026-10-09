/* 
 * Benchmark Sample ID : devign_4569
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=758e8e38eb582e3dc87fd55a1d234c25108a7b7f
 */

static int v9fs_do_lstat(V9fsState *s, V9fsString *path, struct stat *stbuf)

{

    return s->ops->lstat(&s->ctx, path->data, stbuf);

}
