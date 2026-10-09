/* 
 * Benchmark Sample ID : devign_9022
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6e42e6c4b410dbef8b593c2d796a5dad95f89ee4
 */

void rgb16tobgr16(const uint8_t *src, uint8_t *dst, long src_size)

{

	long i;

	long num_pixels = src_size >> 1;



	for(i=0; i<num_pixels; i++)

	{

	    unsigned b,g,r;

	    register uint16_t rgb;

	    rgb = src[2*i];

	    r = rgb&0x1F;

	    g = (rgb&0x7E0)>>5;

	    b = (rgb&0xF800)>>11;

	    dst[2*i] = (b&0x1F) | ((g&0x3F)<<5) | ((r&0x1F)<<11);

	}

}
