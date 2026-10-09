/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2873
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b854bc196f5c4b4e3299c0b0ee63cf828ece9e77
 */

uint32_t omap_badwidth_read32(void *opaque, target_phys_addr_t addr)

{

    OMAP_32B_REG(addr);

    return 0;

}
