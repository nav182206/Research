/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_41
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4774718e5c194026ba5ee7a28d9be49be3080e42
 */

void v9fs_device_unrealize_common(V9fsState *s, Error **errp)

{

    g_free(s->ctx.fs_root);

    g_free(s->tag);

}
