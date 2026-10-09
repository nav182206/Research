/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4561
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

int coroutine_fn bdrv_co_copy_on_readv(BlockDriverState *bs,

    int64_t sector_num, int nb_sectors, QEMUIOVector *qiov)

{

    trace_bdrv_co_copy_on_readv(bs, sector_num, nb_sectors);



    return bdrv_co_do_readv(bs, sector_num, nb_sectors, qiov,

                            BDRV_REQ_COPY_ON_READ);

}
