/* 
 * Benchmark Sample ID : devign_8692
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e30a07d6d70d3073ff61e6db79d61c2b688502f
 */

static void scsi_req_xfer_mode(SCSIRequest *req)

{

    switch (req->cmd.buf[0]) {

    case WRITE_6:

    case WRITE_10:

    case WRITE_VERIFY:

    case WRITE_12:

    case WRITE_VERIFY_12:

    case WRITE_16:

    case WRITE_VERIFY_16:

    case COPY:

    case COPY_VERIFY:

    case COMPARE:

    case CHANGE_DEFINITION:

    case LOG_SELECT:

    case MODE_SELECT:

    case MODE_SELECT_10:

    case SEND_DIAGNOSTIC:

    case WRITE_BUFFER:

    case FORMAT_UNIT:

    case REASSIGN_BLOCKS:

    case SEARCH_EQUAL:

    case SEARCH_HIGH:

    case SEARCH_LOW:

    case UPDATE_BLOCK:

    case WRITE_LONG:

    case WRITE_SAME:

    case SEARCH_HIGH_12:

    case SEARCH_EQUAL_12:

    case SEARCH_LOW_12:

    case MEDIUM_SCAN:

    case SEND_VOLUME_TAG:

    case WRITE_LONG_2:

    case PERSISTENT_RESERVE_OUT:

    case MAINTENANCE_OUT:

        req->cmd.mode = SCSI_XFER_TO_DEV;

        break;

    default:

        if (req->cmd.xfer)

            req->cmd.mode = SCSI_XFER_FROM_DEV;

        else {

            req->cmd.mode = SCSI_XFER_NONE;

        }

        break;

    }

}
