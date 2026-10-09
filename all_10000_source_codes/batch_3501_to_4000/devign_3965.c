/* 
 * Benchmark Sample ID : devign_3965
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0b5a24454fc551f0294fe93821e8c643214a55f5
 */

static void coroutine_fn bdrv_co_do_rw(void *opaque)

{

    BlockAIOCBCoroutine *acb = opaque;

    BlockDriverState *bs = acb->common.bs;



    if (!acb->is_write) {

        acb->req.error = bdrv_co_do_readv(bs, acb->req.sector,

            acb->req.nb_sectors, acb->req.qiov, acb->req.flags);

    } else {

        acb->req.error = bdrv_co_do_writev(bs, acb->req.sector,

            acb->req.nb_sectors, acb->req.qiov, acb->req.flags);

    }



    acb->bh = aio_bh_new(bdrv_get_aio_context(bs), bdrv_co_em_bh, acb);

    qemu_bh_schedule(acb->bh);

}
