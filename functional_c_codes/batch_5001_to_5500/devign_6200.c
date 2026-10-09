/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6200
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=92045d80badc43c9f95897aad675dc7ef17a3b3f
 */

void virtio_queue_set_notification(VirtQueue *vq, int enable)

{

    vq->notification = enable;

    if (vq->vdev->guest_features & (1 << VIRTIO_RING_F_EVENT_IDX)) {

        vring_avail_event(vq, vring_avail_idx(vq));

    } else if (enable) {

        vring_used_flags_unset_bit(vq, VRING_USED_F_NO_NOTIFY);

    } else {

        vring_used_flags_set_bit(vq, VRING_USED_F_NO_NOTIFY);
