/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7951
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=344dc16fae0cb6a011aa5befffc8e7d520b11d5d
 */

static void virtio_queue_host_notifier_read(EventNotifier *n)

{

    VirtQueue *vq = container_of(n, VirtQueue, host_notifier);

    if (event_notifier_test_and_clear(n)) {

        virtio_queue_notify_vq(vq);

    }

}
