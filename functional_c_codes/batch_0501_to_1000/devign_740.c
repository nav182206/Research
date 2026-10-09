/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_740
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dc638fadb54c911019227ae37656560c49a209b9
 */

static int usb_uhci_piix4_initfn(PCIDevice *dev)

{

    UHCIState *s = DO_UPCAST(UHCIState, dev, dev);

    uint8_t *pci_conf = s->dev.config;



    pci_config_set_vendor_id(pci_conf, PCI_VENDOR_ID_INTEL);

    pci_config_set_device_id(pci_conf, PCI_DEVICE_ID_INTEL_82371AB_2);

    return usb_uhci_common_initfn(s);

}
