/* 
 * Benchmark Sample ID : devign_8583
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bec1e9546e03b9e7f5152cf3e8c95cf8acff5e12
 */

static ssize_t local_readlink(FsContext *fs_ctx, V9fsPath *fs_path,

                              char *buf, size_t bufsz)

{

    ssize_t tsize = -1;

    char *buffer;

    char *path = fs_path->data;



    if ((fs_ctx->export_flags & V9FS_SM_MAPPED) ||

        (fs_ctx->export_flags & V9FS_SM_MAPPED_FILE)) {

        int fd;

        buffer = rpath(fs_ctx, path);

        fd = open(buffer, O_RDONLY | O_NOFOLLOW);

        g_free(buffer);

        if (fd == -1) {

            return -1;

        }

        do {

            tsize = read(fd, (void *)buf, bufsz);

        } while (tsize == -1 && errno == EINTR);

        close(fd);

    } else if ((fs_ctx->export_flags & V9FS_SM_PASSTHROUGH) ||

               (fs_ctx->export_flags & V9FS_SM_NONE)) {

        buffer = rpath(fs_ctx, path);

        tsize = readlink(buffer, buf, bufsz);

        g_free(buffer);

    }

    return tsize;

}
