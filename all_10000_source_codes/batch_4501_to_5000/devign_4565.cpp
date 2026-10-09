/* 
 * Benchmark Sample ID : devign_4565
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6acbe4c6f18e7de00481ff30574262b58526de45
 */

static void virtio_net_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    PCIDeviceClass *k = PCI_DEVICE_CLASS(klass);



    k->init = virtio_net_init_pci;

    k->exit = virtio_net_exit_pci;

    k->romfile = "pxe-virtio.rom";

    k->vendor_id = PCI_VENDOR_ID_REDHAT_QUMRANET;

    k->device_id = PCI_DEVICE_ID_VIRTIO_NET;

    k->revision = VIRTIO_PCI_ABI_VERSION;

    k->class_id = PCI_CLASS_NETWORK_ETHERNET;

    dc->alias = "virtio-net";

    dc->reset = virtio_pci_reset;

    dc->props = virtio_net_properties;

}
