/* 
 * Benchmark Sample ID : devign_4318
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a1f0cce2ac0243572ff72aa561da67fe3766a395
 */

static int scsi_handle_rw_error(SCSIDiskReq *r, int error, int type)

{

    int is_read = (type == SCSI_REQ_STATUS_RETRY_READ);

    SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, r->req.dev);

    BlockErrorAction action = bdrv_get_on_error(s->bs, is_read);



    if (action == BLOCK_ERR_IGNORE) {

        bdrv_mon_event(s->bs, BDRV_ACTION_IGNORE, is_read);

        return 0;

    }



    if ((error == ENOSPC && action == BLOCK_ERR_STOP_ENOSPC)

            || action == BLOCK_ERR_STOP_ANY) {



        type &= SCSI_REQ_STATUS_RETRY_TYPE_MASK;

        r->status |= SCSI_REQ_STATUS_RETRY | type;



        bdrv_mon_event(s->bs, BDRV_ACTION_STOP, is_read);

        vm_stop(VMSTOP_DISKFULL);

    } else {

        if (type == SCSI_REQ_STATUS_RETRY_READ) {

            scsi_req_data(&r->req, 0);

        }

        scsi_command_complete(r, CHECK_CONDITION,

                HARDWARE_ERROR);

        bdrv_mon_event(s->bs, BDRV_ACTION_REPORT, is_read);

    }



    return 1;

}
