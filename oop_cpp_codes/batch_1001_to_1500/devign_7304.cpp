/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7304
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void msix_table_mmio_write(void *opaque, target_phys_addr_t addr,

                                  uint64_t val, unsigned size)

{

    PCIDevice *dev = opaque;

    int vector = addr / PCI_MSIX_ENTRY_SIZE;

    bool was_masked;



    was_masked = msix_is_masked(dev, vector);

    pci_set_long(dev->msix_table + addr, val);

    msix_handle_mask_update(dev, vector, was_masked);

}
