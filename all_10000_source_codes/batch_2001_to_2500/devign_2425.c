/* 
 * Benchmark Sample ID : devign_2425
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fa166538743d4e28de7374c41332c3e448826f4b
 */

static int coroutine_fn bdrv_driver_preadv(BlockDriverState *bs,
                                           uint64_t offset, uint64_t bytes,
                                           QEMUIOVector *qiov, int flags)
{
    BlockDriver *drv = bs->drv;
    int64_t sector_num;
    unsigned int nb_sectors;
    if (drv->bdrv_co_preadv) {
        return drv->bdrv_co_preadv(bs, offset, bytes, qiov, flags);
    }
    sector_num = offset >> BDRV_SECTOR_BITS;
    nb_sectors = bytes >> BDRV_SECTOR_BITS;
    assert((offset & (BDRV_SECTOR_SIZE - 1)) == 0);
    assert((bytes & (BDRV_SECTOR_SIZE - 1)) == 0);
    assert((bytes >> BDRV_SECTOR_BITS) <= BDRV_REQUEST_MAX_SECTORS);
    if (drv->bdrv_co_readv) {
        return drv->bdrv_co_readv(bs, sector_num, nb_sectors, qiov);
    } else {
        BlockAIOCB *acb;
        CoroutineIOCompletion co = {
            .coroutine = qemu_coroutine_self(),
        };
        acb = bs->drv->bdrv_aio_readv(bs, sector_num, qiov, nb_sectors,
                                      bdrv_co_io_em_complete, &co);
        if (acb == NULL) {
            return -EIO;
        } else {
            qemu_coroutine_yield();
            return co.ret;
        }
    }
}
