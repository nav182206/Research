/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8661
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3ab0004ae4dffc32494ae84dd15cfaa909a7884
 */

static inline void RENAME(rgb24ToY)(uint8_t *dst, const uint8_t *src, int width, uint32_t *unused)

{

#if COMPILE_TEMPLATE_MMX

    RENAME(bgr24ToY_mmx)(dst, src, width, PIX_FMT_RGB24);

#else

    int i;

    for (i=0; i<width; i++) {

        int r= src[i*3+0];

        int g= src[i*3+1];

        int b= src[i*3+2];



        dst[i]= ((RY*r + GY*g + BY*b + (33<<(RGB2YUV_SHIFT-1)))>>RGB2YUV_SHIFT);

    }

#endif

}
