/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_648
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_opendir(FsContext *ctx,

                         V9fsPath *fs_path, V9fsFidOpenState *fs)

{

    int serrno, fd;



    fs->dir = NULL;

    fd = v9fs_request(ctx->private, T_OPEN, NULL, "sd", fs_path, O_DIRECTORY);

    if (fd < 0) {

        errno = -fd;

        return -1;

    }

    fs->dir = fdopendir(fd);

    if (!fs->dir) {

        serrno = errno;

        close(fd);

        errno = serrno;

        return -1;

    }

    return 0;

}
