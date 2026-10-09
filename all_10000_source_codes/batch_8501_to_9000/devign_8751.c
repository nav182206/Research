/* 
 * Benchmark Sample ID : devign_8751
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

static PXBDev *convert_to_pxb(PCIDevice *dev)

{

    return pci_bus_is_express(dev->bus) ? PXB_PCIE_DEV(dev) : PXB_DEV(dev);

}
