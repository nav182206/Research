/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3087
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

void acpi_pcihp_device_plug_cb(HotplugHandler *hotplug_dev, AcpiPciHpState *s,

                               DeviceState *dev, Error **errp)

{

    PCIDevice *pdev = PCI_DEVICE(dev);

    int slot = PCI_SLOT(pdev->devfn);

    int bsel = acpi_pcihp_get_bsel(pdev->bus);

    if (bsel < 0) {

        error_setg(errp, "Unsupported bus. Bus doesn't have property '"

                   ACPI_PCIHP_PROP_BSEL "' set");

        return;

    }



    /* Don't send event when device is enabled during qemu machine creation:

     * it is present on boot, no hotplug event is necessary. We do send an

     * event when the device is disabled later. */

    if (!dev->hotplugged) {

        return;

    }



    s->acpi_pcihp_pci_status[bsel].up |= (1U << slot);

    acpi_send_event(DEVICE(hotplug_dev), ACPI_PCI_HOTPLUG_STATUS);

}
