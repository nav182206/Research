/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3927
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=758e8e38eb582e3dc87fd55a1d234c25108a7b7f
 */

static int v9fs_do_setuid(V9fsState *s, uid_t uid)

{

    return s->ops->setuid(&s->ctx, uid);

}
