/* 
 * Benchmark Sample ID : devign_1421
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=996a0d76d7e756e4023ef79bc37bfe629b9eaca7
 */

static int local_open(FsContext *ctx, V9fsPath *fs_path,

                      int flags, V9fsFidOpenState *fs)

{

    char *buffer;

    char *path = fs_path->data;

    int fd;



    buffer = rpath(ctx, path);

    fd = open(buffer, flags | O_NOFOLLOW);

    g_free(buffer);

    if (fd == -1) {

        return -1;

    }

    fs->fd = fd;

    return fs->fd;

}
