/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1311
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f7613bee32ebd13ff4a8d721a59cf27b1fe5d94b
 */

static int local_chown(FsContext *ctx, const char *path, uid_t uid, gid_t gid)

{

    return chown(rpath(ctx, path), uid, gid);

}
