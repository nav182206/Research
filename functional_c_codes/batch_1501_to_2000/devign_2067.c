/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2067
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4d43d3f3c8147ade184df9a1e9e82826edd39e19
 */

static void virtio_pci_reset(DeviceState *qdev)

{

    VirtIOPCIProxy *proxy = VIRTIO_PCI(qdev);

    VirtioBusState *bus = VIRTIO_BUS(&proxy->bus);

    virtio_pci_stop_ioeventfd(proxy);

    virtio_bus_reset(bus);

    msix_unuse_all_vectors(&proxy->pci_dev);

    proxy->flags &= ~VIRTIO_PCI_FLAG_BUS_MASTER_BUG;

}
