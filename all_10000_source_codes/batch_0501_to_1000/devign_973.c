/* 
 * Benchmark Sample ID : devign_973
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de08c606f9ddafe647b6843e2b10a6d6030b0fc0
 */

int bdrv_snapshot_load_tmp(BlockDriverState *bs,

        const char *snapshot_name)

{

    BlockDriver *drv = bs->drv;

    if (!drv) {

        return -ENOMEDIUM;

    }

    if (!bs->read_only) {

        return -EINVAL;

    }

    if (drv->bdrv_snapshot_load_tmp) {

        return drv->bdrv_snapshot_load_tmp(bs, snapshot_name);

    }

    return -ENOTSUP;

}
