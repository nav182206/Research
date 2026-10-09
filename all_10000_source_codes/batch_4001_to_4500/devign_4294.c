/* 
 * Benchmark Sample ID : devign_4294
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

static void scsi_cancel_io(SCSIDevice *d, uint32_t tag)

{

    DPRINTF("scsi_cancel_io 0x%x\n", tag);

    SCSIGenericState *s = DO_UPCAST(SCSIGenericState, qdev, d);

    SCSIGenericReq *r;

    DPRINTF("Cancel tag=0x%x\n", tag);

    r = scsi_find_request(s, tag);

    if (r) {

        if (r->req.aiocb)

            bdrv_aio_cancel(r->req.aiocb);

        r->req.aiocb = NULL;

        scsi_req_dequeue(&r->req);

    }

}
