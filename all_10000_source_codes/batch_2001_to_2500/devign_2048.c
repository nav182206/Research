/* 
 * Benchmark Sample ID : devign_2048
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

static SCSIDiskReq *scsi_new_request(SCSIDiskState *s, uint32_t tag,

        uint32_t lun)

{

    SCSIRequest *req;

    SCSIDiskReq *r;



    req = scsi_req_alloc(sizeof(SCSIDiskReq), &s->qdev, tag, lun);

    r = DO_UPCAST(SCSIDiskReq, req, req);

    r->iov.iov_base = qemu_blockalign(s->bs, SCSI_DMA_BUF_SIZE);

    return r;

}
