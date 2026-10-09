/* 
 * Benchmark Sample ID : devign_7468
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=51a135287ae6be62d54d7ac2a99e647cbab1a828
 */

static BlockDriverAIOCB *rbd_aio_rw_vector(BlockDriverState *bs,

                                           int64_t sector_num,

                                           QEMUIOVector *qiov,

                                           int nb_sectors,

                                           BlockDriverCompletionFunc *cb,

                                           void *opaque, int write)

{

    RBDAIOCB *acb;

    RADOSCB *rcb;

    rbd_completion_t c;

    int64_t off, size;

    char *buf;



    BDRVRBDState *s = bs->opaque;



    acb = qemu_aio_get(&rbd_aio_pool, bs, cb, opaque);

    acb->write = write;

    acb->qiov = qiov;

    acb->bounce = qemu_blockalign(bs, qiov->size);

    acb->ret = 0;

    acb->error = 0;

    acb->s = s;

    acb->cancelled = 0;

    acb->bh = NULL;



    if (write) {

        qemu_iovec_to_buffer(acb->qiov, acb->bounce);

    }



    buf = acb->bounce;



    off = sector_num * BDRV_SECTOR_SIZE;

    size = nb_sectors * BDRV_SECTOR_SIZE;



    s->qemu_aio_count++; /* All the RADOSCB */



    rcb = qemu_malloc(sizeof(RADOSCB));

    rcb->done = 0;

    rcb->acb = acb;

    rcb->buf = buf;

    rcb->s = acb->s;

    rcb->size = size;



    if (write) {

        rbd_aio_create_completion(rcb, (rbd_callback_t) rbd_finish_aiocb, &c);

        rbd_aio_write(s->image, off, size, buf, c);

    } else {

        rbd_aio_create_completion(rcb, (rbd_callback_t) rbd_finish_aiocb, &c);

        rbd_aio_read(s->image, off, size, buf, c);

    }



    return &acb->common;

}
