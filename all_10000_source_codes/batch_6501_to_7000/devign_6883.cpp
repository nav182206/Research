/* 
 * Benchmark Sample ID : devign_6883
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static int scsi_handle_rw_error(SCSIDiskReq *r, int error)

{

    bool is_read = (r->req.cmd.xfer == SCSI_XFER_FROM_DEV);

    SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, r->req.dev);

    BlockErrorAction action = bdrv_get_error_action(s->qdev.conf.bs, is_read, error);



    if (action == BLOCK_ERROR_ACTION_REPORT) {

        switch (error) {

        case ENOMEDIUM:

            scsi_check_condition(r, SENSE_CODE(NO_MEDIUM));

            break;

        case ENOMEM:

            scsi_check_condition(r, SENSE_CODE(TARGET_FAILURE));

            break;

        case EINVAL:

            scsi_check_condition(r, SENSE_CODE(INVALID_FIELD));

            break;

        case ENOSPC:

            scsi_check_condition(r, SENSE_CODE(SPACE_ALLOC_FAILED));

            break;

        default:

            scsi_check_condition(r, SENSE_CODE(IO_ERROR));

            break;

        }

    }

    bdrv_error_action(s->qdev.conf.bs, action, is_read, error);

    if (action == BLOCK_ERROR_ACTION_STOP) {

        scsi_req_retry(&r->req);

    }

    return action != BLOCK_ERROR_ACTION_IGNORE;

}
