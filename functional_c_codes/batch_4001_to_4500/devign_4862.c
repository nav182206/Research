/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4862
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=10ee2aaa417d8d8978cdb2bbed55ebb152df5f6b
 */

static void nam_writel (void *opaque, uint32_t addr, uint32_t val)

{

    PCIAC97LinkState *d = opaque;

    AC97LinkState *s = &d->ac97;

    dolog ("U nam writel %#x <- %#x\n", addr, val);

    s->cas = 0;

}
