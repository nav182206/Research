/* 
 * Benchmark Sample ID : devign_7860
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

static SCSIDiskReq *scsi_find_request(SCSIDiskState *s, uint32_t tag)

{

    return DO_UPCAST(SCSIDiskReq, req, scsi_req_find(&s->qdev, tag));

}
