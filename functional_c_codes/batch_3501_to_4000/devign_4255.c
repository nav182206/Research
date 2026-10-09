/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4255
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=35e4e96c4d5bfcf8a22930d8e99f7c8c44420062
 */

void virtio_scsi_handle_cmd_req_submit(VirtIOSCSI *s, VirtIOSCSIReq *req)

{

    if (scsi_req_enqueue(req->sreq)) {

        scsi_req_continue(req->sreq);

    }

    bdrv_io_unplug(req->sreq->dev->conf.bs);

    scsi_req_unref(req->sreq);

}
