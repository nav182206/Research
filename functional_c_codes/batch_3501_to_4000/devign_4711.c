/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4711
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7157e2e23e89adcd436caeab31fdd6b47eded377
 */

void virtio_queue_notify(VirtIODevice *vdev, int n)

{

    if (n < VIRTIO_PCI_QUEUE_MAX) {

        virtio_queue_notify_vq(&vdev->vq[n]);

    }

}
