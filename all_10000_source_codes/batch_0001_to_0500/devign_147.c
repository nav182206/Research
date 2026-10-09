/* 
 * Benchmark Sample ID : devign_147
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

int bdrv_pwrite(BlockDriverState *bs, int64_t offset,

                const void *buf, int bytes)

{

    QEMUIOVector qiov;

    struct iovec iov = {

        .iov_base   = (void *) buf,

        .iov_len    = bytes,

    };



    if (bytes < 0) {

        return -EINVAL;

    }



    qemu_iovec_init_external(&qiov, &iov, 1);

    return bdrv_pwritev(bs, offset, &qiov);

}
