/* 
 * Benchmark Sample ID : devign_7847
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=caffdac363801cd2cf2bf01ad013a8c1e1e43800
 */

static int virtio_blk_pci_init(VirtIOPCIProxy *vpci_dev)

{

    VirtIOBlkPCI *dev = VIRTIO_BLK_PCI(vpci_dev);

    DeviceState *vdev = DEVICE(&dev->vdev);

    virtio_blk_set_conf(vdev, &(dev->blk));

    qdev_set_parent_bus(vdev, BUS(&vpci_dev->bus));

    if (qdev_init(vdev) < 0) {

        return -1;

    }

    return 0;

}
