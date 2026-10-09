/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8088
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t mmio_ide_read(void *opaque, target_phys_addr_t addr,

                              unsigned size)

{

    MMIOState *s = opaque;

    addr >>= s->shift;

    if (addr & 7)

        return ide_ioport_read(&s->bus, addr);

    else

        return ide_data_readw(&s->bus, 0);

}
