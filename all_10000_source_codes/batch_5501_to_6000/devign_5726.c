/* 
 * Benchmark Sample ID : devign_5726
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3c529d935923a70519557d420db1d5a09a65086a
 */

static BlockDriverAIOCB *raw_aio_write(BlockDriverState *bs,

        int64_t sector_num, const uint8_t *buf, int nb_sectors,

        BlockDriverCompletionFunc *cb, void *opaque)

{

    RawAIOCB *acb;



    /*

     * If O_DIRECT is used and the buffer is not aligned fall back

     * to synchronous IO.

     */

    BDRVRawState *s = bs->opaque;



    if (unlikely(s->aligned_buf != NULL && ((uintptr_t) buf % 512))) {

        QEMUBH *bh;

        acb = qemu_aio_get(bs, cb, opaque);

        acb->ret = raw_pwrite(bs, 512 * sector_num, buf, 512 * nb_sectors);

        bh = qemu_bh_new(raw_aio_em_cb, acb);

        qemu_bh_schedule(bh);

        return &acb->common;

    }



    acb = raw_aio_setup(bs, sector_num, (uint8_t*)buf, nb_sectors, cb, opaque);

    if (!acb)

        return NULL;

    if (aio_write(&acb->aiocb) < 0) {

        qemu_aio_release(acb);

        return NULL;

    }

    return &acb->common;

}
