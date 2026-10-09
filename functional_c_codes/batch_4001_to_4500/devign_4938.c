/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4938
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7f526efd17973ec6d2204f7a47b6923e2be31363
 */

void palette8tobgr24(const uint8_t *src, uint8_t *dst, unsigned num_pixels, const uint8_t *palette)

{

	unsigned i;

/*

	writes 1 byte o much and might cause alignment issues on some architectures?

	for(i=0; i<num_pixels; i++)

		((unsigned *)(&dst[i*3])) = ((unsigned *)palette)[ src[i] ];

*/

	for(i=0; i<num_pixels; i++)

	{

		//FIXME slow?

		dst[0]= palette[ src[i]*4+0 ];

		dst[1]= palette[ src[i]*4+1 ];

		dst[2]= palette[ src[i]*4+2 ];

		dst+= 3;

	}

}
