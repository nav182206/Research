/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9219
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b5eff355460643d09e533024360fe0522f368c07
 */

BlockDriverAIOCB *bdrv_aio_write(BlockDriverState *bs, int64_t sector_num,

                                 const uint8_t *buf, int nb_sectors,

                                 BlockDriverCompletionFunc *cb, void *opaque)

{

    BlockDriver *drv = bs->drv;

    BlockDriverAIOCB *ret;



    if (!drv)

        return NULL;

    if (bs->read_only)

        return NULL;

    if (bdrv_wr_badreq_sectors(bs, sector_num, nb_sectors))

        return NULL;

    if (sector_num == 0 && bs->boot_sector_enabled && nb_sectors > 0) {

        memcpy(bs->boot_sector_data, buf, 512);

    }



    ret = drv->bdrv_aio_write(bs, sector_num, buf, nb_sectors, cb, opaque);



    if (ret) {

	/* Update stats even though technically transfer has not happened. */

	bs->wr_bytes += (unsigned) nb_sectors * SECTOR_SIZE;

	bs->wr_ops ++;

    }



    return ret;

}
