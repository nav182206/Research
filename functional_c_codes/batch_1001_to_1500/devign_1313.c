/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1313
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2c6942fa7b332a95286071b92d233853e1000948
 */

int64_t bdrv_getlength(BlockDriverState *bs)

{

    BlockDriver *drv = bs->drv;

    if (!drv)

        return -ENOMEDIUM;



    if (bs->growable || bs->removable) {

        if (drv->bdrv_getlength) {

            return drv->bdrv_getlength(bs);

        }

    }

    return bs->total_sectors * BDRV_SECTOR_SIZE;

}
