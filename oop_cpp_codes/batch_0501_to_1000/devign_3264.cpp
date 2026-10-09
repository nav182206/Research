/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3264
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1adad3cca407f493c3637e20ecd4f7124e69212
 */

static inline void RENAME(bgr24ToY)(uint8_t *dst, const uint8_t *src, long width, uint32_t *unused)

{

#if COMPILE_TEMPLATE_MMX

    RENAME(bgr24ToY_mmx)(dst, src, width, PIX_FMT_BGR24);

#else

    int i;

    for (i=0; i<width; i++) {

        int b= src[i*3+0];

        int g= src[i*3+1];

        int r= src[i*3+2];



        dst[i]= ((RY*r + GY*g + BY*b + (33<<(RGB2YUV_SHIFT-1)))>>RGB2YUV_SHIFT);

    }

#endif /* COMPILE_TEMPLATE_MMX */

}
