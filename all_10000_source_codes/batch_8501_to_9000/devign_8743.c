/* 
 * Benchmark Sample ID : devign_8743
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5a2223ca26b1a34e131b5b9a63599d9426d2c25c
 */

static uint64_t pci_read(void *opaque, hwaddr addr, unsigned int size)

{

    AcpiPciHpState *s = opaque;

    uint32_t val = 0;

    int bsel = s->hotplug_select;



    if (bsel < 0 || bsel > ACPI_PCIHP_MAX_HOTPLUG_BUS) {

        return 0;

    }



    switch (addr) {

    case PCI_UP_BASE - PCI_HOTPLUG_ADDR:

        /* Manufacture an "up" value to cause a device check on any hotplug

         * slot with a device.  Extra device checks are harmless. */

        val = s->acpi_pcihp_pci_status[bsel].device_present &

            s->acpi_pcihp_pci_status[bsel].hotplug_enable;

        ACPI_PCIHP_DPRINTF("pci_up_read %" PRIu32 "\n", val);

        break;

    case PCI_DOWN_BASE - PCI_HOTPLUG_ADDR:

        val = s->acpi_pcihp_pci_status[bsel].down;

        ACPI_PCIHP_DPRINTF("pci_down_read %" PRIu32 "\n", val);

        break;

    case PCI_EJ_BASE - PCI_HOTPLUG_ADDR:

        /* No feature defined yet */

        ACPI_PCIHP_DPRINTF("pci_features_read %" PRIu32 "\n", val);

        break;

    case PCI_RMV_BASE - PCI_HOTPLUG_ADDR:

        val = s->acpi_pcihp_pci_status[bsel].hotplug_enable;

        ACPI_PCIHP_DPRINTF("pci_rmv_read %" PRIu32 "\n", val);

        break;

    case PCI_SEL_BASE - PCI_HOTPLUG_ADDR:

        val = s->hotplug_select;

        ACPI_PCIHP_DPRINTF("pci_sel_read %" PRIu32 "\n", val);

    default:

        break;

    }



    return val;

}
