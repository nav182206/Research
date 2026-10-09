/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3043
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

SCSIRequest *scsi_req_find(SCSIDevice *d, uint32_t tag)

{

    SCSIRequest *req;



    QTAILQ_FOREACH(req, &d->requests, next) {

        if (req->tag == tag) {

            return req;

        }

    }

    return NULL;

}
