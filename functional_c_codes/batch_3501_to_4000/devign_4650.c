/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4650
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8d06b149271cbd5b19bed5bde8da5ecef40ecbc6
 */

static int smc91c111_can_receive(NetClientState *nc)

{

    smc91c111_state *s = qemu_get_nic_opaque(nc);



    if ((s->rcr & RCR_RXEN) == 0 || (s->rcr & RCR_SOFT_RST))

        return 1;

    if (s->allocated == (1 << NUM_PACKETS) - 1)

        return 0;

    return 1;

}
