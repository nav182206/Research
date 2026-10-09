/* 
 * Benchmark Sample ID : devign_2116
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e3187a45dd02a7490f9191c16527dc28a4ba45b9
 */

static int local_chmod(FsContext *fs_ctx, V9fsPath *fs_path, FsCred *credp)

{

    char *buffer;

    int ret = -1;

    char *path = fs_path->data;



    if (fs_ctx->export_flags & V9FS_SM_MAPPED) {

        buffer = rpath(fs_ctx, path);

        ret = local_set_xattr(buffer, credp);

        g_free(buffer);

    } else if (fs_ctx->export_flags & V9FS_SM_MAPPED_FILE) {

        return local_set_mapped_file_attr(fs_ctx, path, credp);

    } else if ((fs_ctx->export_flags & V9FS_SM_PASSTHROUGH) ||

               (fs_ctx->export_flags & V9FS_SM_NONE)) {

        buffer = rpath(fs_ctx, path);

        ret = chmod(buffer, credp->fc_mode);

        g_free(buffer);

    }

    return ret;

}
