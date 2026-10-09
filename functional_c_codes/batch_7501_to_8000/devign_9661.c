/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9661
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_statfs(FsContext *s, V9fsPath *fs_path, struct statfs *stbuf)

{

    int retval;

    retval = v9fs_request(s->private, T_STATFS, stbuf, "s", fs_path);

    if (retval < 0) {

        errno = -retval;

        return -1;

    }

    return retval;

}
