/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1985
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static uint32_t qvirtio_pci_get_features(QVirtioDevice *d)

{

    QVirtioPCIDevice *dev = (QVirtioPCIDevice *)d;

    return qpci_io_readl(dev->pdev, dev->addr + VIRTIO_PCI_HOST_FEATURES);

}
