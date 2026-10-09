/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3747
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3eff1f46f08a360a4ae9f834ce9fef4c45bf6f0f
 */

static void virtio_scsi_fail_cmd_req(VirtIOSCSIReq *req)

{

    req->resp.cmd->response = VIRTIO_SCSI_S_FAILURE;

    virtio_scsi_complete_cmd_req(req);

}
