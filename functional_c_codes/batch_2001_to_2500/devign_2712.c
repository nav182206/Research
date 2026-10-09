/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2712
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint32_t gic_dist_readl(void *opaque, target_phys_addr_t offset)

{

    uint32_t val;

    val = gic_dist_readw(opaque, offset);

    val |= gic_dist_readw(opaque, offset + 2) << 16;

    return val;

}
