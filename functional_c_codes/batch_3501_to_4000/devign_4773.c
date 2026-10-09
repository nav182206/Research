/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4773
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2da0d70d5eebe42f9fcd27ee554419ebe2a5da06
 */

static inline void RENAME(bgr32ToY)(uint8_t *dst, uint8_t *src, int width)

{

	int i;

	for(i=0; i<width; i++)

	{

		int b=  ((uint32_t*)src)[i]&0xFF;

		int g= (((uint32_t*)src)[i]>>8)&0xFF;

		int r= (((uint32_t*)src)[i]>>16)&0xFF;



		dst[i]= ((RY*r + GY*g + BY*b + (33<<(RGB2YUV_SHIFT-1)) )>>RGB2YUV_SHIFT);

	}

}
