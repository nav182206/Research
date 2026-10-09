/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1337
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a697a334b3c4d3250e6420f5d38550ea10eb5319
 */

void virtio_net_exit(VirtIODevice *vdev)

{

    VirtIONet *n = DO_UPCAST(VirtIONet, vdev, vdev);

    qemu_del_vm_change_state_handler(n->vmstate);



    if (n->vhost_started) {

        vhost_net_stop(tap_get_vhost_net(n->nic->nc.peer), vdev);

    }



    qemu_purge_queued_packets(&n->nic->nc);



    unregister_savevm(n->qdev, "virtio-net", n);



    qemu_free(n->mac_table.macs);

    qemu_free(n->vlans);



    qemu_del_timer(n->tx_timer);

    qemu_free_timer(n->tx_timer);



    virtio_cleanup(&n->vdev);

    qemu_del_vlan_client(&n->nic->nc);

}
