/* 
 * Benchmark Sample ID : devign_4744
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f7613bee32ebd13ff4a8d721a59cf27b1fe5d94b
 */

static int v9fs_do_chown(V9fsState *s, V9fsString *path, uid_t uid, gid_t gid)

{

    return s->ops->chown(&s->ctx, path->data, uid, gid);

}
