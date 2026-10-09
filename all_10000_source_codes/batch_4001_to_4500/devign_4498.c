/* 
 * Benchmark Sample ID : devign_4498
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

int bdrv_debug_breakpoint(BlockDriverState *bs, const char *event,

                          const char *tag)

{

    while (bs && bs->drv && !bs->drv->bdrv_debug_breakpoint) {

        bs = bs->file;

    }



    if (bs && bs->drv && bs->drv->bdrv_debug_breakpoint) {

        return bs->drv->bdrv_debug_breakpoint(bs, event, tag);

    }



    return -ENOTSUP;

}
