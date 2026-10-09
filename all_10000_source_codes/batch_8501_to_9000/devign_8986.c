/* 
 * Benchmark Sample ID : devign_8986
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=786a4ea82ec9c87e3a895cf41081029b285a5fe5
 */

static void acpi_pcihp_eject_slot(AcpiPciHpState *s, unsigned bsel, unsigned slots)

{

    BusChild *kid, *next;

    int slot = ffs(slots) - 1;

    PCIBus *bus = acpi_pcihp_find_hotplug_bus(s, bsel);



    if (!bus) {

        return;

    }



    /* Mark request as complete */

    s->acpi_pcihp_pci_status[bsel].down &= ~(1U << slot);

    s->acpi_pcihp_pci_status[bsel].up &= ~(1U << slot);



    QTAILQ_FOREACH_SAFE(kid, &bus->qbus.children, sibling, next) {

        DeviceState *qdev = kid->child;

        PCIDevice *dev = PCI_DEVICE(qdev);

        if (PCI_SLOT(dev->devfn) == slot) {

            if (!acpi_pcihp_pc_no_hotplug(s, dev)) {

                object_unparent(OBJECT(qdev));

            }

        }

    }

}
