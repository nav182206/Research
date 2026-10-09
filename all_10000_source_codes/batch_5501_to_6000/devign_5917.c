/* 
 * Benchmark Sample ID : devign_5917
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a697a334b3c4d3250e6420f5d38550ea10eb5319
 */

static void virtio_net_handle_tx(VirtIODevice *vdev, VirtQueue *vq)

{

    VirtIONet *n = to_virtio_net(vdev);



    if (n->tx_waiting) {

        virtio_queue_set_notification(vq, 1);

        qemu_del_timer(n->tx_timer);

        n->tx_waiting = 0;

        virtio_net_flush_tx(n, vq);

    } else {

        qemu_mod_timer(n->tx_timer,

                       qemu_get_clock(vm_clock) + n->tx_timeout);

        n->tx_waiting = 1;

        virtio_queue_set_notification(vq, 0);

    }

}
