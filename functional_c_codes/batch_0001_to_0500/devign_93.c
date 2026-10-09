/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_93
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b456a71c4a1eb5704d135fd08da9a0de8fd81231
 */

static int scsi_disk_emulate_start_stop(SCSIDiskReq *r)

{

    SCSIRequest *req = &r->req;

    SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, req->dev);

    bool start = req->cmd.buf[4] & 1;

    bool loej = req->cmd.buf[4] & 2; /* load on start, eject on !start */



    if (s->qdev.type == TYPE_ROM && loej) {

        if (!start && !s->tray_open && s->tray_locked) {

            scsi_check_condition(r,

                                 bdrv_is_inserted(s->qdev.conf.bs)

                                 ? SENSE_CODE(ILLEGAL_REQ_REMOVAL_PREVENTED)

                                 : SENSE_CODE(NOT_READY_REMOVAL_PREVENTED));

            return -1;

        }



        if (s->tray_open != !start) {

            bdrv_eject(s->qdev.conf.bs, !start);

            s->tray_open = !start;

        }

    }

    return 0;

}
