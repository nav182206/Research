/* 
 * Benchmark Sample ID : devign_451
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f6049f4483d61fa911a0693c2c48ce8308451d33
 */

void virtio_queue_set_num(VirtIODevice *vdev, int n, int num)

{

    if (num <= VIRTQUEUE_MAX_SIZE) {

        vdev->vq[n].vring.num = num;

        virtqueue_init(&vdev->vq[n]);

    }

}
