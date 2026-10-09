/* 
 * Benchmark Sample ID : devign_806
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f8b6cc0070aab8b75bd082582c829be1353f395f
 */

static int virtio_blk_init_pci(PCIDevice *pci_dev)

{

    VirtIOPCIProxy *proxy = DO_UPCAST(VirtIOPCIProxy, pci_dev, pci_dev);

    VirtIODevice *vdev;



    if (proxy->class_code != PCI_CLASS_STORAGE_SCSI &&

        proxy->class_code != PCI_CLASS_STORAGE_OTHER)

        proxy->class_code = PCI_CLASS_STORAGE_SCSI;



    if (!proxy->block.dinfo) {

        error_report("virtio-blk-pci: drive property not set");

        return -1;

    }

    vdev = virtio_blk_init(&pci_dev->qdev, &proxy->block);

    vdev->nvectors = proxy->nvectors;

    virtio_init_pci(proxy, vdev,

                    PCI_VENDOR_ID_REDHAT_QUMRANET,

                    PCI_DEVICE_ID_VIRTIO_BLOCK,

                    proxy->class_code, 0x00);

    /* make the actual value visible */

    proxy->nvectors = vdev->nvectors;

    return 0;

}
