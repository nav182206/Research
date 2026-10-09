/* 
 * Benchmark Sample ID : devign_2215
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=783e7706937fe15523b609b545587a028a2bdd03
 */

static void virtio_net_handle_tx_bh(VirtIODevice *vdev, VirtQueue *vq)

{

    VirtIONet *n = to_virtio_net(vdev);



    if (unlikely(n->tx_waiting)) {

        return;

    }

    virtio_queue_set_notification(vq, 0);

    qemu_bh_schedule(n->tx_bh);

    n->tx_waiting = 1;

}
