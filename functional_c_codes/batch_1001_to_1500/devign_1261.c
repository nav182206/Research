/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1261
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=879c28133dfa54b780dffbb29e4dcfc6581f6281
 */

static int v9fs_do_symlink(V9fsState *s, V9fsString *oldpath,

                            V9fsString *newpath)

{

    return s->ops->symlink(&s->ctx, oldpath->data, newpath->data);

}
