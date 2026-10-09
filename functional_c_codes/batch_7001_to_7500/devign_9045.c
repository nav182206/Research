/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9045
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e23a1b33b53d25510320b26d9f154e19c6c99725
 */

int pci_vga_init(PCIBus *bus,

                 unsigned long vga_bios_offset, int vga_bios_size)

{

    PCIDevice *dev;



    dev = pci_create(bus, -1, "VGA");

    qdev_prop_set_uint32(&dev->qdev, "bios-offset", vga_bios_offset);

    qdev_prop_set_uint32(&dev->qdev, "bios-size", vga_bios_offset);

    qdev_init(&dev->qdev);



    return 0;

}
