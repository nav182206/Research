/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1064
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bc0f0674f037a01f2ce0870ad6270a356a7a8347
 */

e1000_mmio_read(void *opaque, hwaddr addr, unsigned size)

{

    E1000State *s = opaque;

    unsigned int index = (addr & 0x1ffff) >> 2;



    if (index < NREADOPS && macreg_readops[index])

    {

        return macreg_readops[index](s, index);

    }

    DBGOUT(UNKNOWN, "MMIO unknown read addr=0x%08x\n", index<<2);

    return 0;

}
