/* 
 * Benchmark Sample ID : devign_6035
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

bool bdrv_debug_is_suspended(BlockDriverState *bs, const char *tag)

{

    while (bs && bs->drv && !bs->drv->bdrv_debug_is_suspended) {

        bs = bs->file;

    }



    if (bs && bs->drv && bs->drv->bdrv_debug_is_suspended) {

        return bs->drv->bdrv_debug_is_suspended(bs, tag);

    }



    return false;

}
