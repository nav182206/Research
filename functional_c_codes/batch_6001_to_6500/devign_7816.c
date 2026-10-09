/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7816
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

MemoryRegion *pci_address_space(PCIDevice *dev)

{

    return dev->bus->address_space_mem;

}
