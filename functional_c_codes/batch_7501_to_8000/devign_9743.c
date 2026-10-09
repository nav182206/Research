/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9743
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint32_t dp8393x_readl(void *opaque, target_phys_addr_t addr)

{

    uint32_t v;

    v = dp8393x_readw(opaque, addr);

    v |= dp8393x_readw(opaque, addr + 2) << 16;

    return v;

}
