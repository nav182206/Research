/* 
 * Benchmark Sample ID : devign_8839
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d46636b88339ecc2cb8d10113f45ada164817773
 */

static uint64_t pci_config_get_pref_base(PCIDevice *d,

                                         uint32_t base, uint32_t upper)

{

    uint64_t val;

    val = ((uint64_t)pci_get_word(d->config + base) &

           PCI_PREF_RANGE_MASK) << 16;

    val |= (uint64_t)pci_get_long(d->config + upper) << 32;

    return val;

}
