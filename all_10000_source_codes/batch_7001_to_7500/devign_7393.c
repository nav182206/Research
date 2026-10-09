/* 
 * Benchmark Sample ID : devign_7393
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

void scsi_req_data(SCSIRequest *req, int len)

{

    trace_scsi_req_data(req->dev->id, req->lun, req->tag, len);

    req->bus->ops->complete(req->bus, SCSI_REASON_DATA, req->tag, len);

}
