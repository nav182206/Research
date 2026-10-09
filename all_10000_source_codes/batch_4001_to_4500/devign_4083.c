/* 
 * Benchmark Sample ID : devign_4083
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=44701ab71ad854e6be567a6294f4665f36651076
 */

void msi_uninit(struct PCIDevice *dev)

{

    uint16_t flags;

    uint8_t cap_size;



    if (!(dev->cap_present & QEMU_PCI_CAP_MSI)) {

        return;

    }

    flags = pci_get_word(dev->config + msi_flags_off(dev));

    cap_size = msi_cap_sizeof(flags);

    pci_del_capability(dev, PCI_CAP_ID_MSI, cap_size);

    dev->cap_present &= ~QEMU_PCI_CAP_MSI;



    MSI_DEV_PRINTF(dev, "uninit\n");

}
