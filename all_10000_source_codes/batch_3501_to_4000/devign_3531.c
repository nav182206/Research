/* 
 * Benchmark Sample ID : devign_3531
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint32_t dp8393x_readb(void *opaque, target_phys_addr_t addr)

{

    uint16_t v = dp8393x_readw(opaque, addr & ~0x1);

    return (v >> (8 * (addr & 0x1))) & 0xff;

}
