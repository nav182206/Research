/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_382
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2278a69e7020d86a8c73a28474e7709d3e7d5081
 */

size_t iov_memset(const struct iovec *iov, const unsigned int iov_cnt,

                 size_t iov_off, int fillc, size_t size)

{

    size_t iovec_off, buf_off;

    unsigned int i;



    iovec_off = 0;

    buf_off = 0;

    for (i = 0; i < iov_cnt && size; i++) {

        if (iov_off < (iovec_off + iov[i].iov_len)) {

            size_t len = MIN((iovec_off + iov[i].iov_len) - iov_off , size);



            memset(iov[i].iov_base + (iov_off - iovec_off), fillc, len);



            buf_off += len;

            iov_off += len;

            size -= len;

        }

        iovec_off += iov[i].iov_len;

    }

    return buf_off;

}
