/* 
 * Benchmark Sample ID : devign_9730
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=213189ab65d83ecd9072f27c80a15dcb91b6bdbf
 */

static void scsi_dma_restart_cb(void *opaque, int running, int reason)

{

    SCSIDeviceState *s = opaque;

    SCSIRequest *r = s->requests;

    if (!running)

        return;



    while (r) {

        if (r->status & SCSI_REQ_STATUS_RETRY) {

            r->status &= ~SCSI_REQ_STATUS_RETRY;

            scsi_write_request(r); 

        }

        r = r->next;

    }

}
