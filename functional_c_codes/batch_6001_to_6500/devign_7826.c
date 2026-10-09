/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7826
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fc19f8a02e45c4d8ad24dd7eb374330b03dfc28e
 */

size_t nbd_wr_sync(int fd, void *buffer, size_t size, bool do_read)

{

    size_t offset = 0;



    if (qemu_in_coroutine()) {

        if (do_read) {

            return qemu_co_recv(fd, buffer, size);

        } else {

            return qemu_co_send(fd, buffer, size);

        }

    }



    while (offset < size) {

        ssize_t len;



        if (do_read) {

            len = qemu_recv(fd, buffer + offset, size - offset, 0);

        } else {

            len = send(fd, buffer + offset, size - offset, 0);

        }



        if (len == -1)

            errno = socket_error();



        /* recoverable error */

        if (len == -1 && (errno == EAGAIN || errno == EINTR)) {

            continue;

        }



        /* eof */

        if (len == 0) {

            break;

        }



        /* unrecoverable error */

        if (len == -1) {

            return 0;

        }



        offset += len;

    }



    return offset;

}
