/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9255
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

static SCSIGenericReq *scsi_find_request(SCSIGenericState *s, uint32_t tag)

{

    return DO_UPCAST(SCSIGenericReq, req, scsi_req_find(&s->qdev, tag));

}
