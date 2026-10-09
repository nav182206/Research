/* 
 * Benchmark Sample ID : devign_7751
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint32_t pmac_ide_readw (void *opaque,target_phys_addr_t addr)

{

    uint16_t retval;

    MACIOIDEState *d = opaque;



    addr = (addr & 0xFFF) >> 4;

    if (addr == 0) {

        retval = ide_data_readw(&d->bus, 0);

    } else {

        retval = 0xFFFF;

    }

    retval = bswap16(retval);

    return retval;

}
