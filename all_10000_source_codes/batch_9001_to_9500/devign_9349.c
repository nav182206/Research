/* 
 * Benchmark Sample ID : devign_9349
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=82cbbdc6a0958b49c77639a60906e30d02e6bb7b
 */

void qemu_aio_set_fd_handler(int fd,

                             IOHandler *io_read,

                             IOHandler *io_write,

                             AioFlushHandler *io_flush,

                             void *opaque)

{

    aio_set_fd_handler(qemu_aio_context, fd, io_read, io_write, io_flush,

                       opaque);



    qemu_set_fd_handler2(fd, NULL, io_read, io_write, opaque);

}
