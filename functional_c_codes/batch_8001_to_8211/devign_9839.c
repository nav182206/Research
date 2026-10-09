/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9839
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12848bfc5d719bad536c5448205a3226be1fda47
 */

static int local_chown(FsContext *fs_ctx, const char *path, FsCred *credp)

{

    if ((credp->fc_uid == -1 && credp->fc_gid == -1) ||

            (fs_ctx->fs_sm == SM_PASSTHROUGH)) {

        return lchown(rpath(fs_ctx, path), credp->fc_uid, credp->fc_gid);

    } else if (fs_ctx->fs_sm == SM_MAPPED) {

        return local_set_xattr(rpath(fs_ctx, path), credp);

    } else if (fs_ctx->fs_sm == SM_PASSTHROUGH) {

        return lchown(rpath(fs_ctx, path), credp->fc_uid, credp->fc_gid);

    }

    return -1;

}
