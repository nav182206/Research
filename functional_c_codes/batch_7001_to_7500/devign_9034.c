/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9034
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1e3f77b53a803a6c63fa64829f1be557b8226288
 */

static void RENAME(uyvytoyuv422)(uint8_t *ydst, uint8_t *udst, uint8_t *vdst, const uint8_t *src,

                                 int width, int height,

                                 int lumStride, int chromStride, int srcStride)

{

    int y;

    const int chromWidth = FF_CEIL_RSHIFT(width, 1);



    for (y=0; y<height; y++) {

        RENAME(extract_even)(src+1, ydst, width);

        RENAME(extract_even2)(src, udst, vdst, chromWidth);



        src += srcStride;

        ydst+= lumStride;

        udst+= chromStride;

        vdst+= chromStride;

    }

    __asm__(

            EMMS"       \n\t"

            SFENCE"     \n\t"

            ::: "memory"

        );

}
