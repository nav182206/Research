/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4239
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dc88a467ec7214c3086094033daf2aba554337b1
 */

bdrv_co_rw_vmstate(BlockDriverState *bs, QEMUIOVector *qiov, int64_t pos,

                   bool is_read)

{

    BlockDriver *drv = bs->drv;



    if (!drv) {

        return -ENOMEDIUM;

    } else if (drv->bdrv_load_vmstate) {

        return is_read ? drv->bdrv_load_vmstate(bs, qiov, pos)

                       : drv->bdrv_save_vmstate(bs, qiov, pos);

    } else if (bs->file) {

        return bdrv_co_rw_vmstate(bs->file->bs, qiov, pos, is_read);

    }



    return -ENOTSUP;

}
