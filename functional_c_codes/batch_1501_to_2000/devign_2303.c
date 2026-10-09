/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2303
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6ff0ad6bfd0f00a3d54705811ee91a7ce3c22cda
 */

static inline void RENAME(yuy2ToUV)(uint8_t *dstU, uint8_t *dstV, uint8_t *src1, uint8_t *src2, int width)

{

#ifdef HAVE_MMXFIXME

#else

	int i;

	for(i=0; i<width; i++)

	{

		dstU[i]= (src1[4*i + 1] + src2[4*i + 1])>>1;

		dstV[i]= (src1[4*i + 3] + src2[4*i + 3])>>1;

	}

#endif

}
