/* 
 * Benchmark Sample ID : devign_6998
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60a8d8023473dd24957b3a66824f66cd35b80d64
 */

static void virtio_pci_reset(DeviceState *qdev)

{

    VirtIOPCIProxy *proxy = VIRTIO_PCI(qdev);

    VirtioBusState *bus = VIRTIO_BUS(&proxy->bus);

    int i;



    virtio_pci_stop_ioeventfd(proxy);

    virtio_bus_reset(bus);

    msix_unuse_all_vectors(&proxy->pci_dev);



    for (i = 0; i < VIRTIO_QUEUE_MAX; i++) {

        proxy->vqs[i].enabled = 0;





    }

}
