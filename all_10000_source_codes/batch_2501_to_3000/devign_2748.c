/* 
 * Benchmark Sample ID : devign_2748
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void bitband_writew(void *opaque, target_phys_addr_t offset,

                           uint32_t value)

{

    uint32_t addr;

    uint16_t mask;

    uint16_t v;

    addr = bitband_addr(opaque, offset) & ~1;

    mask = (1 << ((offset >> 2) & 15));

    mask = tswap16(mask);

    cpu_physical_memory_read(addr, (uint8_t *)&v, 2);

    if (value & 1)

        v |= mask;

    else

        v &= ~mask;

    cpu_physical_memory_write(addr, (uint8_t *)&v, 2);

}
