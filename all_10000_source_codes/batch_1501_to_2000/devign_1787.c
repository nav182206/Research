/* 
 * Benchmark Sample ID : devign_1787
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

e1000_mmio_write(void *opaque, target_phys_addr_t addr, uint64_t val,

                 unsigned size)

{

    E1000State *s = opaque;

    unsigned int index = (addr & 0x1ffff) >> 2;



    if (index < NWRITEOPS && macreg_writeops[index]) {

        macreg_writeops[index](s, index, val);

    } else if (index < NREADOPS && macreg_readops[index]) {

        DBGOUT(MMIO, "e1000_mmio_writel RO %x: 0x%04"PRIx64"\n", index<<2, val);

    } else {

        DBGOUT(UNKNOWN, "MMIO unknown write addr=0x%08x,val=0x%08"PRIx64"\n",

               index<<2, val);

    }

}
