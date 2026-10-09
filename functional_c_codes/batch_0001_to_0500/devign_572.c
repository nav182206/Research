/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_572
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e911765cbb9e9ddf5d952c88bb52180a62c6cea0
 */

unsigned iov_copy(struct iovec *dst_iov, unsigned int dst_iov_cnt,

                 const struct iovec *iov, unsigned int iov_cnt,

                 size_t offset, size_t bytes)

{

    size_t len;

    unsigned int i, j;

    for (i = 0, j = 0; i < iov_cnt && j < dst_iov_cnt && bytes; i++) {

        if (offset >= iov[i].iov_len) {

            offset -= iov[i].iov_len;

            continue;

        }

        len = MIN(bytes, iov[i].iov_len - offset);



        dst_iov[j].iov_base = iov[i].iov_base + offset;

        dst_iov[j].iov_len = len;

        j++;

        bytes -= len;

        offset = 0;

    }

    assert(offset == 0);

    return j;

}
