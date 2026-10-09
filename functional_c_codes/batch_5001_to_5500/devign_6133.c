/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6133
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=71d0770c4cec9f1dc04f4dadcbf7fd6c335030a9
 */

BlockDriverAIOCB *bdrv_aio_readv(BlockDriverState *bs, int64_t sector_num,
                                 QEMUIOVector *iov, int nb_sectors,
                                 BlockDriverCompletionFunc *cb, void *opaque)
{
    return bdrv_aio_rw_vector(bs, sector_num, iov, nb_sectors,
                              cb, opaque, 0);
}
