/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3767
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static void bdrv_co_complete(BlockAIOCBCoroutine *acb)

{

    if (!acb->need_bh) {

        acb->common.cb(acb->common.opaque, acb->req.error);

        qemu_aio_unref(acb);

    }

}
