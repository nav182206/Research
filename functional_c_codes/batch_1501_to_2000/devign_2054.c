/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2054
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7292b0477ac8a864af9bf97b63362c40062ab805
 */

static void DEF(avg, pixels16_x2)(uint8_t *block, const uint8_t *pixels, ptrdiff_t line_size, int h)

{

    MOVQ_BFE(mm6);

    JUMPALIGN();

    do {

        __asm__ volatile(

            "movq  %1, %%mm0            \n\t"

            "movq  1%1, %%mm1           \n\t"

            "movq  %0, %%mm3            \n\t"

            PAVGB(%%mm0, %%mm1, %%mm2, %%mm6)

            PAVGB_MMX(%%mm3, %%mm2, %%mm0, %%mm6)

            "movq  %%mm0, %0            \n\t"

            "movq  8%1, %%mm0           \n\t"

            "movq  9%1, %%mm1           \n\t"

            "movq  8%0, %%mm3           \n\t"

            PAVGB(%%mm0, %%mm1, %%mm2, %%mm6)

            PAVGB_MMX(%%mm3, %%mm2, %%mm0, %%mm6)

            "movq  %%mm0, 8%0           \n\t"

            :"+m"(*block)

            :"m"(*pixels)

            :"memory");

        pixels += line_size;

        block += line_size;

    } while (--h);

}
