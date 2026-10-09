/* 
 * Benchmark Sample ID : devign_6907
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6e42e6c4b410dbef8b593c2d796a5dad95f89ee4
 */

void palette8torgb15(const uint8_t *src, uint8_t *dst, long num_pixels, const uint8_t *palette)

{

	long i;

	for(i=0; i<num_pixels; i++)

		((uint16_t *)dst)[i] = ((uint16_t *)palette)[ src[i] ];

}
