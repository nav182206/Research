/* 
 * Benchmark Sample ID : devign_1219
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c39ce112b60ffafbaf700853e32bea74cbb2c148
 */

int32_t scsi_req_enqueue(SCSIRequest *req, uint8_t *buf)

{

    int32_t rc;



    assert(!req->enqueued);

    scsi_req_ref(req);

    req->enqueued = true;

    QTAILQ_INSERT_TAIL(&req->dev->requests, req, next);



    scsi_req_ref(req);

    rc = req->ops->send_command(req, buf);

    scsi_req_unref(req);

    return rc;

}
