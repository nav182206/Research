/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5326
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0b5a24454fc551f0294fe93821e8c643214a55f5
 */

static void bdrv_co_em_bh(void *opaque)

{

    BlockAIOCBCoroutine *acb = opaque;



    acb->common.cb(acb->common.opaque, acb->req.error);



    qemu_bh_delete(acb->bh);

    qemu_aio_unref(acb);

}
