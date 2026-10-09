/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8508
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4fc9af53d88c0a2a810704a06cb39a7182982e4e
 */

BlockDriverAIOCB *bdrv_aio_read(BlockDriverState *bs, int64_t sector_num,

                                uint8_t *buf, int nb_sectors,

                                BlockDriverCompletionFunc *cb, void *opaque)

{

    BlockDriver *drv = bs->drv;

    BlockDriverAIOCB *ret;



    if (!drv)

        return NULL;



    /* XXX: we assume that nb_sectors == 0 is suppored by the async read */

    if (sector_num == 0 && bs->boot_sector_enabled && nb_sectors > 0) {

        memcpy(buf, bs->boot_sector_data, 512);

        sector_num++;

        nb_sectors--;

        buf += 512;

    }



    ret = drv->bdrv_aio_read(bs, sector_num, buf, nb_sectors, cb, opaque);



    if (ret) {

	/* Update stats even though technically transfer has not happened. */

	bs->rd_bytes += (unsigned) nb_sectors * SECTOR_SIZE;

	bs->rd_ops ++;

    }



    return ret;

}
