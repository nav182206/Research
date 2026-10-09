/* 
 * Benchmark Sample ID : devign_6434
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e6478e7d4f2c4b607069bf488d57089a9d3244b
 */

void qemu_set_cloexec(int fd)

{

    int f;

    f = fcntl(fd, F_GETFD);

    fcntl(fd, F_SETFD, f | FD_CLOEXEC);

}
