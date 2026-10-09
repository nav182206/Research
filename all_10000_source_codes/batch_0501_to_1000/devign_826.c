/* 
 * Benchmark Sample ID : devign_826
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2da0d70d5eebe42f9fcd27ee554419ebe2a5da06
 */

static inline void RENAME(bgr15ToUV)(uint8_t *dstU, uint8_t *dstV, uint8_t *src1, uint8_t *src2, int width)

{

	int i;

        assert(src1==src2);

	for(i=0; i<width; i++)

	{

		int d0= ((uint32_t*)src1)[i];



		int dl= (d0&0x03E07C1F);

		int dh= ((d0>>5)&0x03E0F81F);



		int dh2= (dh>>11) + (dh<<21);

		int d= dh2 + dl;



		int b= d&0x7F;

		int r= (d>>10)&0x7F;

		int g= d>>21;

		dstU[i]= ((RU*r + GU*g + BU*b)>>(RGB2YUV_SHIFT+1-3)) + 128;

		dstV[i]= ((RV*r + GV*g + BV*b)>>(RGB2YUV_SHIFT+1-3)) + 128;

	}

}
