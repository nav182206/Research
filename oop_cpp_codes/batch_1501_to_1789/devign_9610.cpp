/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9610
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d581eb7ca4b58649ade5fb7570ecf6b4b9a41879
 */

static void scsi_dma_restart_bh(void *opaque)

{

    SCSIDevice *s = opaque;

    SCSIRequest *req, *next;



    qemu_bh_delete(s->bh);

    s->bh = NULL;



    QTAILQ_FOREACH_SAFE(req, &s->requests, next, next) {

        scsi_req_ref(req);

        if (req->retry) {

            req->retry = false;

            switch (req->cmd.mode) {

            case SCSI_XFER_FROM_DEV:

            case SCSI_XFER_TO_DEV:

                scsi_req_continue(req);

                break;

            case SCSI_XFER_NONE:

                assert(!req->sg);

                scsi_req_dequeue(req);

                scsi_req_enqueue(req);

                break;

            }

        }

        scsi_req_unref(req);

    }

}
