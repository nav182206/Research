/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_454
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void cirrus_linear_bitblt_write(void *opaque,

                                       target_phys_addr_t addr,

                                       uint64_t val,

                                       unsigned size)

{

    CirrusVGAState *s = opaque;



    if (s->cirrus_srcptr != s->cirrus_srcptr_end) {

	/* bitblt */

	*s->cirrus_srcptr++ = (uint8_t) val;

	if (s->cirrus_srcptr >= s->cirrus_srcptr_end) {

	    cirrus_bitblt_cputovideo_next(s);

	}

    }

}
