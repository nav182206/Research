/* 
 * Benchmark Sample ID : devign_4423
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=25f8e2f512d87f0a77fc5c0b367dd200a7834d21
 */

static int pci_piix4_ide_initfn(PCIDevice *dev)

{

    PCIIDEState *d = DO_UPCAST(PCIIDEState, dev, dev);



    pci_config_set_vendor_id(d->dev.config, PCI_VENDOR_ID_INTEL);

    pci_config_set_device_id(d->dev.config, PCI_DEVICE_ID_INTEL_82371AB);

    return pci_piix_ide_initfn(d);

}
