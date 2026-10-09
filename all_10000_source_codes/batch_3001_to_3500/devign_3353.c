/* 
 * Benchmark Sample ID : devign_3353
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=07b70bfbb3f3aea9ce7a3a1da78cbfa8ae6bbce6
 */

int bdrv_can_snapshot(BlockDriverState *bs)

{

    BlockDriver *drv = bs->drv;

    if (!drv || bdrv_is_removable(bs) || bdrv_is_read_only(bs)) {

        return 0;

    }



    if (!drv->bdrv_snapshot_create) {

        if (bs->file != NULL) {

            return bdrv_can_snapshot(bs->file);

        }

        return 0;

    }



    return 1;

}
