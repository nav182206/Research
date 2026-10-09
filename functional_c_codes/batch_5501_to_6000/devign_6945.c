/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6945
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8f90b5e91df59fde0dfecc6738ff39f3edf14be5
 */

void bdrv_io_unplugged_end(BlockDriverState *bs)

{

    BdrvChild *child;



    assert(bs->io_plug_disabled);

    QLIST_FOREACH(child, &bs->children, next) {

        bdrv_io_unplugged_end(child->bs);

    }



    if (--bs->io_plug_disabled == 0 && bs->io_plugged > 0) {

        BlockDriver *drv = bs->drv;

        if (drv && drv->bdrv_io_plug) {

            drv->bdrv_io_plug(bs);

        }

    }

}
