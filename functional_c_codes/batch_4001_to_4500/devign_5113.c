/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5113
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

void scsi_req_complete(SCSIRequest *req)

{

    assert(req->status != -1);

    scsi_req_ref(req);

    scsi_req_dequeue(req);

    req->bus->ops->complete(req->bus, SCSI_REASON_DONE,

                            req->tag,

                            req->status);

    scsi_req_unref(req);

}
