/* 
 * Benchmark Sample ID : devign_5474
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=da15ee5134f715adb07e3688a1c6e8b42cb6ac94
 */

static int bdrv_rw_co(BlockDriverState *bs, int64_t sector_num, uint8_t *buf,
                      int nb_sectors, bool is_write, BdrvRequestFlags flags)
{
    QEMUIOVector qiov;
    struct iovec iov = {
        .iov_base = (void *)buf,
        .iov_len = nb_sectors * BDRV_SECTOR_SIZE,
    };
    qemu_iovec_init_external(&qiov, &iov, 1);
    return bdrv_prwv_co(bs, sector_num << BDRV_SECTOR_BITS,
                        &qiov, is_write, flags);
