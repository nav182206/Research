/* 
 * Benchmark Sample ID : devign_8031
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de08c606f9ddafe647b6843e2b10a6d6030b0fc0
 */

int bdrv_snapshot_delete(BlockDriverState *bs, const char *snapshot_id)

{

    BlockDriver *drv = bs->drv;

    if (!drv)

        return -ENOMEDIUM;

    if (drv->bdrv_snapshot_delete)

        return drv->bdrv_snapshot_delete(bs, snapshot_id);

    if (bs->file)

        return bdrv_snapshot_delete(bs->file, snapshot_id);

    return -ENOTSUP;

}
