/* 
 * Benchmark Sample ID : devign_6307
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint32_t bitband_readb(void *opaque, target_phys_addr_t offset)

{

    uint8_t v;

    cpu_physical_memory_read(bitband_addr(opaque, offset), &v, 1);

    return (v & (1 << ((offset >> 2) & 7))) != 0;

}
