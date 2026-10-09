/* 
 * Benchmark Sample ID : devign_863
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static void qvirtio_pci_set_status(QVirtioDevice *d, uint8_t status)

{

    QVirtioPCIDevice *dev = (QVirtioPCIDevice *)d;

    qpci_io_writeb(dev->pdev, dev->addr + VIRTIO_PCI_STATUS, status);

}
