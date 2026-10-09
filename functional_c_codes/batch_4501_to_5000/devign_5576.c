/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5576
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3eff1f46f08a360a4ae9f834ce9fef4c45bf6f0f
 */

static void virtio_scsi_request_cancelled(SCSIRequest *r)

{

    VirtIOSCSIReq *req = r->hba_private;



    if (!req) {

        return;

    }

    if (req->dev->resetting) {

        req->resp.cmd->response = VIRTIO_SCSI_S_RESET;

    } else {

        req->resp.cmd->response = VIRTIO_SCSI_S_ABORTED;

    }

    virtio_scsi_complete_cmd_req(req);

}
