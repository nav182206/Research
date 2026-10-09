/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7213
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3f5ec2b5e92706e3b807059f79b1fb5d936e567
 */

static ssize_t tap_receive_iov(void *opaque, const struct iovec *iov,

                               int iovcnt)

{

    TAPState *s = opaque;

    ssize_t len;



    do {

        len = writev(s->fd, iov, iovcnt);

    } while (len == -1 && (errno == EINTR || errno == EAGAIN));



    return len;

}
