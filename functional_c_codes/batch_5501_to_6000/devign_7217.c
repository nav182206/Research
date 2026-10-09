/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7217
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

void scsi_req_cancel(SCSIRequest *req)

{

    trace_scsi_req_cancel(req->dev->id, req->lun, req->tag);

    if (!req->enqueued) {

        return;

    }

    scsi_req_ref(req);

    scsi_req_dequeue(req);

    req->io_canceled = true;

    if (req->aiocb) {

        bdrv_aio_cancel(req->aiocb);

    }

}
