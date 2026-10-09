/* 
 * Benchmark Sample ID : devign_2583
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7f526efd17973ec6d2204f7a47b6923e2be31363
 */

void rgb15tobgr16(const uint8_t *src, uint8_t *dst, unsigned int src_size)

{

	unsigned i;

	unsigned num_pixels = src_size >> 1;

	

	for(i=0; i<num_pixels; i++)

	{

	    unsigned b,g,r;

	    register uint16_t rgb;

	    rgb = src[2*i];

	    r = rgb&0x1F;

	    g = (rgb&0x3E0)>>5;

	    b = (rgb&0x7C00)>>10;

	    dst[2*i] = (b&0x1F) | ((g&0x3F)<<5) | ((r&0x1F)<<11);

	}

}
