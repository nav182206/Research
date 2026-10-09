/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2631
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1adad3cca407f493c3637e20ecd4f7124e69212
 */

static void RENAME(yuyvtoyuv420)(uint8_t *ydst, uint8_t *udst, uint8_t *vdst, const uint8_t *src,

                                      long width, long height,

                                      long lumStride, long chromStride, long srcStride)

{

    long y;

    const long chromWidth= -((-width)>>1);



    for (y=0; y<height; y++) {

        RENAME(extract_even)(src, ydst, width);

        if(y&1) {

            RENAME(extract_odd2avg)(src-srcStride, src, udst, vdst, chromWidth);

            udst+= chromStride;

            vdst+= chromStride;

        }



        src += srcStride;

        ydst+= lumStride;

    }

#if COMPILE_TEMPLATE_MMX

    __asm__(

            EMMS"       \n\t"

            SFENCE"     \n\t"

            ::: "memory"

        );

#endif

}
