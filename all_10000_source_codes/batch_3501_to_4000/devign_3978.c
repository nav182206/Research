/* 
 * Benchmark Sample ID : devign_3978
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

void pci_unregister_vga(PCIDevice *pci_dev)

{

    if (!pci_dev->has_vga) {

        return;

    }



    memory_region_del_subregion(pci_dev->bus->address_space_mem,

                                pci_dev->vga_regions[QEMU_PCI_VGA_MEM]);

    memory_region_del_subregion(pci_dev->bus->address_space_io,

                                pci_dev->vga_regions[QEMU_PCI_VGA_IO_LO]);

    memory_region_del_subregion(pci_dev->bus->address_space_io,

                                pci_dev->vga_regions[QEMU_PCI_VGA_IO_HI]);

    pci_dev->has_vga = false;

}
