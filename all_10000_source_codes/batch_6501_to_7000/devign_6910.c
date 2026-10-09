/* 
 * Benchmark Sample ID : devign_6910
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=302a0d3ed721e4c30c6a2a37f64c60b50ffd33b9
 */

static struct iovec *adjust_sg(struct iovec *sg, int len, int *iovcnt)

{

    while (len && *iovcnt) {

        if (len < sg->iov_len) {

            sg->iov_len -= len;

            sg->iov_base += len;

            len = 0;

        } else {

            len -= sg->iov_len;

            sg++;

            *iovcnt -= 1;

        }

    }



    return sg;

}
