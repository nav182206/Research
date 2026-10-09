/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5443
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ca749954b09b89e22cd69c4949fb7e689b057963
 */

int qemu_lock_fd_test(int fd, int64_t start, int64_t len, bool exclusive)

{

    int ret;

    struct flock fl = {

        .l_whence = SEEK_SET,

        .l_start  = start,

        .l_len    = len,

        .l_type   = exclusive ? F_WRLCK : F_RDLCK,

    };

    ret = fcntl(fd, QEMU_GETLK, &fl);

    if (ret == -1) {

        return -errno;

    } else {

        return fl.l_type == F_UNLCK ? 0 : -EAGAIN;

    }

}
