/* 
 * Benchmark Sample ID : devign_2593
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d2767edec582558f1e6c52e1dd9370d62e2b30fc
 */

static int local_rename(FsContext *ctx, const char *oldpath,

                        const char *newpath)

{

    int err;

    char *buffer, *buffer1;



    if (ctx->export_flags & V9FS_SM_MAPPED_FILE) {

        err = local_create_mapped_attr_dir(ctx, newpath);

        if (err < 0) {

            return err;

        }

        /* rename the .virtfs_metadata files */

        buffer = local_mapped_attr_path(ctx, oldpath);

        buffer1 = local_mapped_attr_path(ctx, newpath);

        err = rename(buffer, buffer1);

        g_free(buffer);

        g_free(buffer1);

        if (err < 0 && errno != ENOENT) {

            return err;

        }

    }



    buffer = rpath(ctx, oldpath);

    buffer1 = rpath(ctx, newpath);

    err = rename(buffer, buffer1);

    g_free(buffer);

    g_free(buffer1);

    return err;

}
