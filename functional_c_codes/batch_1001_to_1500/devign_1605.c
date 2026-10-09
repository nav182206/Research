/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1605
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6ff0ad6bfd0f00a3d54705811ee91a7ce3c22cda
 */

static inline void RENAME(yuy2ToY)(uint8_t *dst, uint8_t *src, int width)

{

#ifdef HAVE_MMXFIXME

#else

	int i;

	for(i=0; i<width; i++)

		dst[i]= src[2*i];

#endif

}
