/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_562
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2e29bd04786003561303dcad940b38afe790fb9b
 */

static uint32_t pci_unin_config_readl (void *opaque,

                                       target_phys_addr_t addr)

{

    UNINState *s = opaque;



    return s->config_reg;

}
