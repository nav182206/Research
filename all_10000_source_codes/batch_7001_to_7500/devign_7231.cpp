/* 
 * Benchmark Sample ID : devign_7231
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5fb6c7a8b26eab1a22207d24b4784bd2b39ab54b
 */

static ssize_t vnc_tls_push(gnutls_transport_ptr_t transport,

                            const void *data,

                            size_t len) {

    struct VncState *vs = (struct VncState *)transport;

    int ret;



 retry:

    ret = send(vs->csock, data, len, 0);

    if (ret < 0) {

	if (errno == EINTR)

	    goto retry;

	return -1;

    }

    return ret;

}
