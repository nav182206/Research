/* 
 * Benchmark Sample ID : devign_446
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5b5cb08683b6715a2aca5314168e68ff0665912b
 */

void msix_write_config(PCIDevice *dev, uint32_t addr,

                       uint32_t val, int len)

{

    unsigned enable_pos = dev->msix_cap + MSIX_CONTROL_OFFSET;

    if (addr + len <= enable_pos || addr > enable_pos)

        return;



    if (msix_enabled(dev))

        qemu_set_irq(dev->irq[0], 0);

}
