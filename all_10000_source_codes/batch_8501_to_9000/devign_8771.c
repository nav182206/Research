/* 
 * Benchmark Sample ID : devign_8771
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static int bdrv_rw_co(BlockDriverState *bs, int64_t sector_num, uint8_t *buf,

                      int nb_sectors, bool is_write, BdrvRequestFlags flags)

{

    QEMUIOVector qiov;

    struct iovec iov = {

        .iov_base = (void *)buf,

        .iov_len = nb_sectors * BDRV_SECTOR_SIZE,

    };



    if (nb_sectors < 0 || nb_sectors > BDRV_REQUEST_MAX_SECTORS) {

        return -EINVAL;

    }



    qemu_iovec_init_external(&qiov, &iov, 1);

    return bdrv_prwv_co(bs, sector_num << BDRV_SECTOR_BITS,

                        &qiov, is_write, flags);

}
