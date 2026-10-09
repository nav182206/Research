/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2134
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint32_t dp8393x_readw(void *opaque, target_phys_addr_t addr)

{

    dp8393xState *s = opaque;

    int reg;



    if ((addr & ((1 << s->it_shift) - 1)) != 0) {

        return 0;

    }



    reg = addr >> s->it_shift;

    return read_register(s, reg);

}
