/* 
 * Benchmark Sample ID : devign_9170
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dd3dd4ba7b949662d2c67a4c041549b3d79c4b0e
 */

static bool virtio_queue_host_notifier_aio_poll(void *opaque)

{

    EventNotifier *n = opaque;

    VirtQueue *vq = container_of(n, VirtQueue, host_notifier);

    bool progress;



    if (virtio_queue_empty(vq)) {

        return false;

    }



    progress = virtio_queue_notify_aio_vq(vq);



    /* In case the handler function re-enabled notifications */

    virtio_queue_set_notification(vq, 0);

    return progress;

}
