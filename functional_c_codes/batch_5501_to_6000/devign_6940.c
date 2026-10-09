/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6940
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d8b7e0adf562277180f96ecbd7f1777a384a0308
 */

static BlockDriverAIOCB *raw_aio_writev(BlockDriverState *bs,

    int64_t sector_num, QEMUIOVector *qiov, int nb_sectors,

    BlockDriverCompletionFunc *cb, void *opaque)

{

    return bdrv_aio_writev(bs->file, sector_num, qiov, nb_sectors, cb, opaque);

}
