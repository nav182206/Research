/* 
 * Benchmark Sample ID : devign_4454
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e80bf9351f8fec9085c46df6da075efd5e71003
 */

int qemu_sendv(int sockfd, struct iovec *iov, int len, int iov_offset)

{

    return do_sendv_recvv(sockfd, iov, len, iov_offset, 1);

}
