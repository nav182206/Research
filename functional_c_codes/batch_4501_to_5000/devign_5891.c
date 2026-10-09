/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5891
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=44701ab71ad854e6be567a6294f4665f36651076
 */

void msix_reset(PCIDevice *dev)

{

    if (!(dev->cap_present & QEMU_PCI_CAP_MSIX))

        return;

    msix_free_irq_entries(dev);

    dev->config[dev->msix_cap + MSIX_CONTROL_OFFSET] &=

	    ~dev->wmask[dev->msix_cap + MSIX_CONTROL_OFFSET];

    memset(dev->msix_table_page, 0, MSIX_PAGE_SIZE);

    msix_mask_all(dev, dev->msix_entries_nr);

}
