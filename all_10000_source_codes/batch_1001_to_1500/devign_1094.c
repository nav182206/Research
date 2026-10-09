/* 
 * Benchmark Sample ID : devign_1094
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=af19f78f2fe2b969104d4419efd25fdee90a2814
 */

void dsputil_init_ppc(void)

{

    // Common optimisations whether Altivec or not



    // ... pending ...



#if HAVE_ALTIVEC

    if (has_altivec()) {

        // Altivec specific optimisations

        pix_abs16x16 = pix_abs16x16_altivec;

        pix_abs8x8 = pix_abs8x8_altivec;

        pix_sum = pix_sum_altivec;

        diff_pixels = diff_pixels_altivec;

        get_pixels = get_pixels_altivec;

    } else

#endif

    {

        // Non-AltiVec PPC optimisations



        // ... pending ...

    }

}
