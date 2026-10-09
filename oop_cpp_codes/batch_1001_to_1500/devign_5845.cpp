/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5845
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=857d4f46c31d2f4d57d2f0fad9dfb584262bf9b9
 */

static void bdrv_aio_bh_cb(void *opaque)

{

    BlockDriverAIOCBSync *acb = opaque;



    if (!acb->is_write)

        qemu_iovec_from_buf(acb->qiov, 0, acb->bounce, acb->qiov->size);

    qemu_vfree(acb->bounce);

    acb->common.cb(acb->common.opaque, acb->ret);

    qemu_bh_delete(acb->bh);

    acb->bh = NULL;

    qemu_aio_release(acb);

}
