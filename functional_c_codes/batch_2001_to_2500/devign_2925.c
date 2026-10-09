/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2925
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int unix_get_buffer(void *opaque, uint8_t *buf, int64_t pos, int size)

{

    QEMUFileSocket *s = opaque;

    ssize_t len;



    for (;;) {

        len = read(s->fd, buf, size);

        if (len != -1) {

            break;

        }

        if (errno == EAGAIN) {

            yield_until_fd_readable(s->fd);

        } else if (errno != EINTR) {

            break;

        }

    }



    if (len == -1) {

        len = -errno;

    }

    return len;

}
