/* 
 * Benchmark Sample ID : devign_4753
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

ImageInfoSpecific *bdrv_get_specific_info(BlockDriverState *bs)

{

    BlockDriver *drv = bs->drv;

    if (drv && drv->bdrv_get_specific_info) {

        return drv->bdrv_get_specific_info(bs);

    }

    return NULL;

}
