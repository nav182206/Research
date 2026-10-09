/* 
 * Benchmark Sample ID : devign_7560
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5b956f415a356449a4171d5e0c7d9a25bbc84b5a
 */

static void scsi_write_complete_noio(SCSIDiskReq *r, int ret)

{

    uint32_t n;



    assert (r->req.aiocb == NULL);



    if (r->req.io_canceled) {

        scsi_req_cancel_complete(&r->req);

        goto done;

    }



    if (ret < 0) {

        if (scsi_handle_rw_error(r, -ret, false)) {

            goto done;

        }

    }



    n = r->qiov.size / 512;

    r->sector += n;

    r->sector_count -= n;

    if (r->sector_count == 0) {

        scsi_write_do_fua(r);

        return;

    } else {

        scsi_init_iovec(r, SCSI_DMA_BUF_SIZE);

        DPRINTF("Write complete tag=0x%x more=%zd\n", r->req.tag, r->qiov.size);

        scsi_req_data(&r->req, r->qiov.size);

    }



done:

    scsi_req_unref(&r->req);

}
