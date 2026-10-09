/* 
 * Benchmark Sample ID : devign_4088
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3f5ec2b5e92706e3b807059f79b1fb5d936e567
 */

static int smc91c111_can_receive(void *opaque)

{

    smc91c111_state *s = (smc91c111_state *)opaque;



    if ((s->rcr & RCR_RXEN) == 0 || (s->rcr & RCR_SOFT_RST))

        return 1;

    if (s->allocated == (1 << NUM_PACKETS) - 1)

        return 0;

    return 1;

}
