/* 
 * Benchmark Sample ID : devign_3216
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void dp8393x_writew(void *opaque, target_phys_addr_t addr, uint32_t val)

{

    dp8393xState *s = opaque;

    int reg;



    if ((addr & ((1 << s->it_shift) - 1)) != 0) {

        return;

    }



    reg = addr >> s->it_shift;



    write_register(s, reg, (uint16_t)val);

}
