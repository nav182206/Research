/* 
 * Benchmark Sample ID : devign_1001
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

void qemu_set_fd_handler(int fd,

                         IOHandler *fd_read,

                         IOHandler *fd_write,

                         void *opaque)

{

    iohandler_init();

    aio_set_fd_handler(iohandler_ctx, fd, false,

                       fd_read, fd_write, NULL, opaque);

}
