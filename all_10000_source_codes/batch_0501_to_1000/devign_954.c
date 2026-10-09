/* 
 * Benchmark Sample ID : devign_954
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7285477ab11831b1cf56e45878a89170dd06d9b9
 */

static void scsi_free_request(SCSIRequest *req)

{

    SCSIDiskReq *r = DO_UPCAST(SCSIDiskReq, req, req);



    qemu_vfree(r->iov.iov_base);

}
