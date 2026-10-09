/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_51
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

void virtio_scsi_handle_cmd_req_submit(VirtIOSCSI *s, VirtIOSCSIReq *req)

{

    SCSIRequest *sreq = req->sreq;

    if (scsi_req_enqueue(sreq)) {

        scsi_req_continue(sreq);

    }

    bdrv_io_unplug(sreq->dev->conf.bs);

    scsi_req_unref(sreq);

}
