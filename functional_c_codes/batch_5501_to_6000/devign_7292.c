/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7292
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

static void pci_change_irq_level(PCIDevice *pci_dev, int irq_num, int change)

{

    PCIBus *bus;

    for (;;) {

        bus = pci_dev->bus;

        irq_num = bus->map_irq(pci_dev, irq_num);

        if (bus->set_irq)

            break;

        pci_dev = bus->parent_dev;

    }

    bus->irq_count[irq_num] += change;

    bus->set_irq(bus->irq_opaque, irq_num, bus->irq_count[irq_num] != 0);

}
