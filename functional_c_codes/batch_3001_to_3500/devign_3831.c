/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3831
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void dp8393x_writel(void *opaque, target_phys_addr_t addr, uint32_t val)

{

    dp8393x_writew(opaque, addr, val & 0xffff);

    dp8393x_writew(opaque, addr + 2, (val >> 16) & 0xffff);

}
