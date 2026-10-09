/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2921
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=83d768b5640946b7da55ce8335509df297e2c7cd
 */

void virtio_scsi_dataplane_notify(VirtIODevice *vdev, VirtIOSCSIReq *req)

{

    if (virtio_should_notify(vdev, req->vq)) {

        event_notifier_set(virtio_queue_get_guest_notifier(req->vq));

    }

}
