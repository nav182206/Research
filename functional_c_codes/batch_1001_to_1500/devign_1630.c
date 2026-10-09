/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1630
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=10ee2aaa417d8d8978cdb2bbed55ebb152df5f6b
 */

static uint32_t nam_readw (void *opaque, uint32_t addr)

{

    PCIAC97LinkState *d = opaque;

    AC97LinkState *s = &d->ac97;

    uint32_t val = ~0U;

    uint32_t index = addr - s->base[0];

    s->cas = 0;

    val = mixer_load (s, index);

    return val;

}
