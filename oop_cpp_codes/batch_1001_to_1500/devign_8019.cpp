/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8019
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a1f0cce2ac0243572ff72aa561da67fe3766a395
 */

static void scsi_dma_restart_bh(void *opaque)

{

    SCSIDiskState *s = opaque;

    SCSIRequest *req;

    SCSIDiskReq *r;



    qemu_bh_delete(s->bh);

    s->bh = NULL;



    QTAILQ_FOREACH(req, &s->qdev.requests, next) {

        r = DO_UPCAST(SCSIDiskReq, req, req);

        if (r->status & SCSI_REQ_STATUS_RETRY) {

            int status = r->status;

            int ret;



            r->status &=

                ~(SCSI_REQ_STATUS_RETRY | SCSI_REQ_STATUS_RETRY_TYPE_MASK);



            switch (status & SCSI_REQ_STATUS_RETRY_TYPE_MASK) {

            case SCSI_REQ_STATUS_RETRY_READ:

                scsi_read_data(&r->req);

                break;

            case SCSI_REQ_STATUS_RETRY_WRITE:

                scsi_write_data(&r->req);

                break;

            case SCSI_REQ_STATUS_RETRY_FLUSH:

                ret = scsi_disk_emulate_command(r, r->iov.iov_base);

                if (ret == 0) {

                    scsi_command_complete(r, GOOD, NO_SENSE);

                }

            }

        }

    }

}
