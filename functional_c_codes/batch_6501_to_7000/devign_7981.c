/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7981
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=25db9ebe15125deb32958c6df74996f745edf1f9
 */

void virtio_queue_notify(VirtIODevice *vdev, int n)

{

    if (n < VIRTIO_PCI_QUEUE_MAX && vdev->vq[n].vring.desc) {

        trace_virtio_queue_notify(vdev, n, &vdev->vq[n]);

        vdev->vq[n].handle_output(vdev, &vdev->vq[n]);

    }

}
