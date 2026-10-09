/* 
 * Benchmark Sample ID : devign_513
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static uint32_t e1000e_macreg_read(e1000e_device *d, uint32_t reg)

{

    return qpci_io_readl(d->pci_dev, d->mac_regs + reg);

}
