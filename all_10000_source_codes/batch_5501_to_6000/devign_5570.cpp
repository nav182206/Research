/* 
 * Benchmark Sample ID : devign_5570
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1adad3cca407f493c3637e20ecd4f7124e69212
 */

static void RENAME(uyvytoyuv422)(uint8_t *ydst, uint8_t *udst, uint8_t *vdst, const uint8_t *src,

                                      long width, long height,

                                      long lumStride, long chromStride, long srcStride)

{

    long y;

    const long chromWidth= -((-width)>>1);



    for (y=0; y<height; y++) {

        RENAME(extract_even)(src+1, ydst, width);

        RENAME(extract_even2)(src, udst, vdst, chromWidth);



        src += srcStride;

        ydst+= lumStride;

        udst+= chromStride;

        vdst+= chromStride;

    }

#if COMPILE_TEMPLATE_MMX

    __asm__(

            EMMS"       \n\t"

            SFENCE"     \n\t"

            ::: "memory"

        );

#endif

}
