/* 
 * Benchmark Sample ID : devign_7451
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=75af1f34cd5b07c3c7fcf86dfc99a42de48a600d
 */

static int coroutine_fn bdrv_co_do_readv(BlockDriverState *bs,

    int64_t sector_num, int nb_sectors, QEMUIOVector *qiov,

    BdrvRequestFlags flags)

{

    if (nb_sectors < 0 || nb_sectors > (UINT_MAX >> BDRV_SECTOR_BITS)) {

        return -EINVAL;

    }



    return bdrv_co_do_preadv(bs, sector_num << BDRV_SECTOR_BITS,

                             nb_sectors << BDRV_SECTOR_BITS, qiov, flags);

}
