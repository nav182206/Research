/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6560
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a8f2e5c8fffbaf7fbd4f0efc8efbeebade78008f
 */

static void virtio_scsi_handle_ctrl(VirtIODevice *vdev, VirtQueue *vq)

{

    VirtIOSCSI *s = (VirtIOSCSI *)vdev;

    VirtIOSCSIReq *req;



    if (s->ctx && !s->dataplane_started) {

        virtio_scsi_dataplane_start(s);

        return;

    }

    while ((req = virtio_scsi_pop_req(s, vq))) {

        virtio_scsi_handle_ctrl_req(s, req);

    }

}
