/* 
 * Benchmark Sample ID : devign_7966
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static uint8_t qvirtio_pci_get_status(QVirtioDevice *d)

{

    QVirtioPCIDevice *dev = (QVirtioPCIDevice *)d;

    return qpci_io_readb(dev->pdev, dev->addr + VIRTIO_PCI_STATUS);

}
