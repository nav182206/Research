/* 
 * Benchmark Sample ID : devign_2791
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e80bf9351f8fec9085c46df6da075efd5e71003
 */

int coroutine_fn qemu_co_recvv(int sockfd, struct iovec *iov,

                               int len, int iov_offset)

{

    int total = 0;

    int ret;

    while (len) {

        ret = qemu_recvv(sockfd, iov, len, iov_offset + total);

        if (ret < 0) {

            if (errno == EAGAIN) {

                qemu_coroutine_yield();

                continue;

            }

            if (total == 0) {

                total = -1;

            }

            break;

        }

        if (ret == 0) {

            break;

        }

        total += ret, len -= ret;

    }



    return total;

}
