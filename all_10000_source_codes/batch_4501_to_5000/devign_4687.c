/* 
 * Benchmark Sample ID : devign_4687
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

BlockAIOCB *dma_bdrv_read(BlockDriverState *bs,

                          QEMUSGList *sg, uint64_t sector,

                          void (*cb)(void *opaque, int ret), void *opaque)

{

    return dma_bdrv_io(bs, sg, sector, bdrv_aio_readv, cb, opaque,

                       DMA_DIRECTION_FROM_DEVICE);

}
