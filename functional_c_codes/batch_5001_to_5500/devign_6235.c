/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6235
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void scsi_write_do_fua(SCSIDiskReq *r)

{

    SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, r->req.dev);



    if (r->req.io_canceled) {

        scsi_req_cancel_complete(&r->req);

        goto done;

    }



    if (scsi_is_cmd_fua(&r->req.cmd)) {

        block_acct_start(bdrv_get_stats(s->qdev.conf.bs), &r->acct, 0,

                         BLOCK_ACCT_FLUSH);

        r->req.aiocb = bdrv_aio_flush(s->qdev.conf.bs, scsi_aio_complete, r);

        return;

    }



    scsi_req_complete(&r->req, GOOD);



done:

    scsi_req_unref(&r->req);

}
