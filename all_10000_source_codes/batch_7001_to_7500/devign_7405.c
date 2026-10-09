/* 
 * Benchmark Sample ID : devign_7405
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a0e640a87210b1e986bcd4e7f7de03beb3db0a4a
 */

static int local_remove(FsContext *ctx, const char *path)

{

    int err;

    struct stat stbuf;

    char *buffer;



    if (ctx->export_flags & V9FS_SM_MAPPED_FILE) {

        buffer = rpath(ctx, path);

        err =  lstat(buffer, &stbuf);

        g_free(buffer);

        if (err) {

            goto err_out;

        }

        /*

         * If directory remove .virtfs_metadata contained in the

         * directory

         */

        if (S_ISDIR(stbuf.st_mode)) {

            buffer = g_strdup_printf("%s/%s/%s", ctx->fs_root,

                                     path, VIRTFS_META_DIR);

            err = remove(buffer);

            g_free(buffer);

            if (err < 0 && errno != ENOENT) {

                /*

                 * We didn't had the .virtfs_metadata file. May be file created

                 * in non-mapped mode ?. Ignore ENOENT.

                 */

                goto err_out;

            }

        }

        /*

         * Now remove the name from parent directory

         * .virtfs_metadata directory

         */

        buffer = local_mapped_attr_path(ctx, path);

        err = remove(buffer);

        g_free(buffer);

        if (err < 0 && errno != ENOENT) {

            /*

             * We didn't had the .virtfs_metadata file. May be file created

             * in non-mapped mode ?. Ignore ENOENT.

             */

            goto err_out;

        }

    }



    buffer = rpath(ctx, path);

    err = remove(buffer);

    g_free(buffer);

err_out:

    return err;

}
