/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2006
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

static void scsi_write_request(SCSIDiskReq *r)

{

    SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, r->req.dev);

    uint32_t n;



    /* No data transfer may already be in progress */

    assert(r->req.aiocb == NULL);



    n = r->iov.iov_len / 512;

    if (n) {

        qemu_iovec_init_external(&r->qiov, &r->iov, 1);

        r->req.aiocb = bdrv_aio_writev(s->bs, r->sector, &r->qiov, n,

                                   scsi_write_complete, r);

        if (r->req.aiocb == NULL) {

            scsi_write_complete(r, -EIO);

        }

    } else {

        /* Invoke completion routine to fetch data from host.  */

        scsi_write_complete(r, 0);

    }

}
