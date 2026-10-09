/* 
 * Benchmark Sample ID : devign_1894
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7f526efd17973ec6d2204f7a47b6923e2be31363
 */

void palette8torgb16(const uint8_t *src, uint8_t *dst, unsigned num_pixels, const uint8_t *palette)

{

	unsigned i;

	for(i=0; i<num_pixels; i++)

		((uint16_t *)dst)[i] = ((uint16_t *)palette)[ src[i] ];

}
