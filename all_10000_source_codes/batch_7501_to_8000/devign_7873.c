/* 
 * Benchmark Sample ID : devign_7873
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static BlockAIOCB *bdrv_co_aio_rw_vector(BlockDriverState *bs,

                                         int64_t sector_num,

                                         QEMUIOVector *qiov,

                                         int nb_sectors,

                                         BdrvRequestFlags flags,

                                         BlockCompletionFunc *cb,

                                         void *opaque,

                                         bool is_write)

{

    Coroutine *co;

    BlockAIOCBCoroutine *acb;



    acb = qemu_aio_get(&bdrv_em_co_aiocb_info, bs, cb, opaque);

    acb->need_bh = true;

    acb->req.error = -EINPROGRESS;

    acb->req.sector = sector_num;

    acb->req.nb_sectors = nb_sectors;

    acb->req.qiov = qiov;

    acb->req.flags = flags;

    acb->is_write = is_write;



    co = qemu_coroutine_create(bdrv_co_do_rw);

    qemu_coroutine_enter(co, acb);



    bdrv_co_maybe_schedule_bh(acb);

    return &acb->common;

}
