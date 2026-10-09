/* 
 * Benchmark Sample ID : devign_6524
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6e42e6c4b410dbef8b593c2d796a5dad95f89ee4
 */

void palette8torgb32(const uint8_t *src, uint8_t *dst, long num_pixels, const uint8_t *palette)

{

	long i;



/*

	for(i=0; i<num_pixels; i++)

		((unsigned *)dst)[i] = ((unsigned *)palette)[ src[i] ];

*/



	for(i=0; i<num_pixels; i++)

	{

		#ifdef WORDS_BIGENDIAN

			dst[3]= palette[ src[i]*4+2 ];

			dst[2]= palette[ src[i]*4+1 ];

			dst[1]= palette[ src[i]*4+0 ];

		#else

		//FIXME slow?

			dst[0]= palette[ src[i]*4+2 ];

			dst[1]= palette[ src[i]*4+1 ];

			dst[2]= palette[ src[i]*4+0 ];

			//dst[3]= 0; /* do we need this cleansing? */

		#endif

		dst+= 4;

	}

}
