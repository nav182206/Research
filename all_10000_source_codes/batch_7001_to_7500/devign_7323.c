/* 
 * Benchmark Sample ID : devign_7323
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e23a1b33b53d25510320b26d9f154e19c6c99725
 */

void pci_cmd646_ide_init(PCIBus *bus, DriveInfo **hd_table,

                         int secondary_ide_enabled)

{

    PCIDevice *dev;



    dev = pci_create(bus, -1, "CMD646 IDE");

    qdev_prop_set_uint32(&dev->qdev, "secondary", secondary_ide_enabled);

    qdev_init(&dev->qdev);



    pci_ide_create_devs(dev, hd_table);

}
