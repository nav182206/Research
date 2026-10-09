/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4373
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3daa41078aedf227ec98b0d1c9d56b77b6d20153
 */

void scsi_req_cancel_async(SCSIRequest *req, Notifier *notifier)

{

    trace_scsi_req_cancel(req->dev->id, req->lun, req->tag);

    if (notifier) {

        notifier_list_add(&req->cancel_notifiers, notifier);











    scsi_req_ref(req);

    scsi_req_dequeue(req);

    req->io_canceled = true;

    if (req->aiocb) {

        blk_aio_cancel_async(req->aiocb);

    } else {

        scsi_req_cancel_complete(req);
