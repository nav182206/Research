/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9931
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=83d768b5640946b7da55ce8335509df297e2c7cd
 */

static void virtio_queue_guest_notifier_read(EventNotifier *n)

{

    VirtQueue *vq = container_of(n, VirtQueue, guest_notifier);

    if (event_notifier_test_and_clear(n)) {

        virtio_irq(vq);

    }

}
