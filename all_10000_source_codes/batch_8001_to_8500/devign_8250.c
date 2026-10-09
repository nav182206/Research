/* 
 * Benchmark Sample ID : devign_8250
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4fa4ce7107c6ec432f185307158c5df91ce54308
 */

static const char *local_mapped_attr_path(FsContext *ctx,

                                          const char *path, char *buffer)

{

    char *dir_name;

    char *tmp_path = g_strdup(path);

    char *base_name = basename(tmp_path);



    /* NULL terminate the directory */

    dir_name = tmp_path;

    *(base_name - 1) = '\0';



    snprintf(buffer, PATH_MAX, "%s/%s/%s/%s",

             ctx->fs_root, dir_name, VIRTFS_META_DIR, base_name);

    g_free(tmp_path);

    return buffer;

}
