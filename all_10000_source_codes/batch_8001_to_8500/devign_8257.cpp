/* 
 * Benchmark Sample ID : devign_8257
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=44701ab71ad854e6be567a6294f4665f36651076
 */

void msix_save(PCIDevice *dev, QEMUFile *f)

{

    unsigned n = dev->msix_entries_nr;



    if (!(dev->cap_present & QEMU_PCI_CAP_MSIX)) {

        return;

    }



    qemu_put_buffer(f, dev->msix_table_page, n * PCI_MSIX_ENTRY_SIZE);

    qemu_put_buffer(f, dev->msix_table_page + MSIX_PAGE_PENDING, (n + 7) / 8);

}
