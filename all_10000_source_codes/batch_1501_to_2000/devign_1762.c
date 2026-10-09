/* 
 * Benchmark Sample ID : devign_1762
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static ssize_t socket_writev_buffer(void *opaque, struct iovec *iov, int iovcnt,

                                    int64_t pos)

{

    QEMUFileSocket *s = opaque;

    ssize_t len;

    ssize_t size = iov_size(iov, iovcnt);



    len = iov_send(s->fd, iov, iovcnt, 0, size);

    if (len < size) {

        len = -socket_error();

    }

    return len;

}
