/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_251
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

void bdrv_aio_cancel(BlockAIOCB *acb)

{

    qemu_aio_ref(acb);

    bdrv_aio_cancel_async(acb);

    while (acb->refcnt > 1) {

        if (acb->aiocb_info->get_aio_context) {

            aio_poll(acb->aiocb_info->get_aio_context(acb), true);

        } else if (acb->bs) {

            aio_poll(bdrv_get_aio_context(acb->bs), true);

        } else {

            abort();

        }

    }

    qemu_aio_unref(acb);

}
