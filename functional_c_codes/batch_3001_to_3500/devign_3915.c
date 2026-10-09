/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3915
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e7b9bc3e89152f14f426fa4d150d2a6ca02583c1
 */

static int dec_21154_pci_host_init(PCIDevice *d)

{

    /* PCI2PCI bridge same values as PearPC - check this */

    pci_config_set_vendor_id(d->config, PCI_VENDOR_ID_DEC);

    pci_config_set_device_id(d->config, PCI_DEVICE_ID_DEC_21154);

    pci_set_byte(d->config + PCI_REVISION_ID, 0x02);

    pci_config_set_class(d->config, PCI_CLASS_BRIDGE_PCI);

    return 0;

}
