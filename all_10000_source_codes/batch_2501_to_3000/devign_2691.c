/* 
 * Benchmark Sample ID : devign_2691
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f8a83245d9ec685bc6aa6173d6765fe03e20688f
 */

static void scsi_remove_request(SCSIDiskReq *r)

{

    qemu_free(r->iov.iov_base);

    scsi_req_free(&r->req);

}
