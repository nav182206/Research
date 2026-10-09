/* 
 * Benchmark Sample ID : devign_4890
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static void bdrv_aio_bh_cb(void *opaque)

{

    BlockAIOCBSync *acb = opaque;



    if (!acb->is_write && acb->ret >= 0) {

        qemu_iovec_from_buf(acb->qiov, 0, acb->bounce, acb->qiov->size);

    }

    qemu_vfree(acb->bounce);

    acb->common.cb(acb->common.opaque, acb->ret);

    qemu_bh_delete(acb->bh);

    acb->bh = NULL;

    qemu_aio_unref(acb);

}
