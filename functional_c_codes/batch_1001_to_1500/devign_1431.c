/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1431
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4fa4ce7107c6ec432f185307158c5df91ce54308
 */

static void local_mapped_file_attr(FsContext *ctx, const char *path,

                                   struct stat *stbuf)

{

    FILE *fp;

    char buf[ATTR_MAX];

    char attr_path[PATH_MAX];



    local_mapped_attr_path(ctx, path, attr_path);

    fp = local_fopen(attr_path, "r");

    if (!fp) {

        return;

    }

    memset(buf, 0, ATTR_MAX);

    while (fgets(buf, ATTR_MAX, fp)) {

        if (!strncmp(buf, "virtfs.uid", 10)) {

            stbuf->st_uid = atoi(buf+11);

        } else if (!strncmp(buf, "virtfs.gid", 10)) {

            stbuf->st_gid = atoi(buf+11);

        } else if (!strncmp(buf, "virtfs.mode", 11)) {

            stbuf->st_mode = atoi(buf+12);

        } else if (!strncmp(buf, "virtfs.rdev", 11)) {

            stbuf->st_rdev = atoi(buf+12);

        }

        memset(buf, 0, ATTR_MAX);

    }

    fclose(fp);

}
