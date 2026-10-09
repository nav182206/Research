/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8957
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t macio_nvram_readb(void *opaque, target_phys_addr_t addr,

                                  unsigned size)

{

    MacIONVRAMState *s = opaque;

    uint32_t value;



    addr = (addr >> s->it_shift) & (s->size - 1);

    value = s->data[addr];

    NVR_DPRINTF("readb addr %04x val %x\n", (int)addr, value);



    return value;

}
