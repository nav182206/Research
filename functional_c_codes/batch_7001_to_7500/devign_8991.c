/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8991
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad2d30f79d3b0812f02c741be2189796b788d6d7
 */

static void scsi_remove_request(SCSIGenericReq *r)

{

    qemu_free(r->buf);

    scsi_req_free(&r->req);

}
