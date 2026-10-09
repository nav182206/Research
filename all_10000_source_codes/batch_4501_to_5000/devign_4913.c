/* 
 * Benchmark Sample ID : devign_4913
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=08844473820c93541fc47bdfeae0f2cc88cfab59
 */

static int coroutine_fn bdrv_co_writev_em(BlockDriverState *bs,

                                         int64_t sector_num, int nb_sectors,

                                         QEMUIOVector *iov)

{

    return bdrv_co_io_em(bs, sector_num, nb_sectors, iov, true);

}
