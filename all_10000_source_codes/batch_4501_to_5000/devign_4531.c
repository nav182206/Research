/* 
 * Benchmark Sample ID : devign_4531
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

SCSIRequest *scsi_req_alloc(size_t size, SCSIDevice *d, uint32_t tag, uint32_t lun)

{

    SCSIRequest *req;



    req = qemu_mallocz(size);

    /* Two references: one is passed back to the HBA, one is in d->requests.  */

    req->refcount = 2;

    req->bus = scsi_bus_from_device(d);

    req->dev = d;

    req->tag = tag;

    req->lun = lun;

    req->status = -1;

    req->enqueued = true;

    trace_scsi_req_alloc(req->dev->id, req->lun, req->tag);

    QTAILQ_INSERT_TAIL(&d->requests, req, next);

    return req;

}
