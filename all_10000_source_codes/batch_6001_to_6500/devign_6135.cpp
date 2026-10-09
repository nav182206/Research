/* 
 * Benchmark Sample ID : devign_6135
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

BlockAIOCB *bdrv_aio_discard(BlockDriverState *bs,

        int64_t sector_num, int nb_sectors,

        BlockCompletionFunc *cb, void *opaque)

{

    Coroutine *co;

    BlockAIOCBCoroutine *acb;



    trace_bdrv_aio_discard(bs, sector_num, nb_sectors, opaque);



    acb = qemu_aio_get(&bdrv_em_co_aiocb_info, bs, cb, opaque);

    acb->need_bh = true;

    acb->req.error = -EINPROGRESS;

    acb->req.sector = sector_num;

    acb->req.nb_sectors = nb_sectors;

    co = qemu_coroutine_create(bdrv_aio_discard_co_entry);

    qemu_coroutine_enter(co, acb);



    bdrv_co_maybe_schedule_bh(acb);

    return &acb->common;

}
