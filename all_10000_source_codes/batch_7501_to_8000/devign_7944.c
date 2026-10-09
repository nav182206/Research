/* 
 * Benchmark Sample ID : devign_7944
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d369f20763a857eac544a5289a046d0285a91df8
 */

static int local_chown(FsContext *fs_ctx, V9fsPath *fs_path, FsCred *credp)

{

    char *buffer;

    int ret = -1;

    char *path = fs_path->data;



    if ((credp->fc_uid == -1 && credp->fc_gid == -1) ||

        (fs_ctx->export_flags & V9FS_SM_PASSTHROUGH) ||

        (fs_ctx->export_flags & V9FS_SM_NONE)) {

        buffer = rpath(fs_ctx, path);

        ret = lchown(buffer, credp->fc_uid, credp->fc_gid);

        g_free(buffer);

    } else if (fs_ctx->export_flags & V9FS_SM_MAPPED) {

        buffer = rpath(fs_ctx, path);

        ret = local_set_xattr(buffer, credp);

        g_free(buffer);

    } else if (fs_ctx->export_flags & V9FS_SM_MAPPED_FILE) {

        return local_set_mapped_file_attr(fs_ctx, path, credp);

    }

    return ret;

}
