/* 
 * Benchmark Sample ID : devign_1264
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3ceef24f4fee8d5ed96b8c4a5d3e80c0a651f0b
 */

static uint32_t slavio_serial_mem_readb(void *opaque, target_phys_addr_t addr)

{

    SerialState *ser = opaque;

    ChannelState *s;

    uint32_t saddr;

    uint32_t ret;

    int channel;



    saddr = (addr & 3) >> 1;

    channel = (addr & SERIAL_MAXADDR) >> 2;

    s = &ser->chn[channel];

    switch (saddr) {

    case 0:

	SER_DPRINTF("Read channel %c, reg[%d] = %2.2x\n", CHN_C(s), s->reg, s->rregs[s->reg]);

	ret = s->rregs[s->reg];

	s->reg = 0;

	return ret;

    case 1:

	s->rregs[0] &= ~1;

        clr_rxint(s);

	if (s->type == kbd || s->type == mouse)

	    ret = get_queue(s);

	else

	    ret = s->rx;

	SER_DPRINTF("Read channel %c, ch %d\n", CHN_C(s), ret);

	return ret;

    default:

	break;

    }

    return 0;

}
