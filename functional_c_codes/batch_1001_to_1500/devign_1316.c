/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1316
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3f5ec2b5e92706e3b807059f79b1fb5d936e567
 */

static void mipsnet_receive(void *opaque, const uint8_t *buf, size_t size)

{

    MIPSnetState *s = opaque;



#ifdef DEBUG_MIPSNET_RECEIVE

    printf("mipsnet: receiving len=%d\n", size);

#endif

    if (!mipsnet_can_receive(opaque))

        return;



    s->busy = 1;



    /* Just accept everything. */



    /* Write packet data. */

    memcpy(s->rx_buffer, buf, size);



    s->rx_count = size;

    s->rx_read = 0;



    /* Now we can signal we have received something. */

    s->intctl |= MIPSNET_INTCTL_RXDONE;

    mipsnet_update_irq(s);

}
