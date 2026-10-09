/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4085
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3f5ec2b5e92706e3b807059f79b1fb5d936e567
 */

static int nic_can_receive(void *opaque)

{

    dp8393xState *s = opaque;



    if (!(s->regs[SONIC_CR] & SONIC_CR_RXEN))

        return 0;

    if (s->regs[SONIC_ISR] & SONIC_ISR_RBE)

        return 0;

    return 1;

}
