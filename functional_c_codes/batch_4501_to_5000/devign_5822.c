/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5822
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6a4832caaede15e3d918b1408ff83fe30324507b
 */

void ff_avg_dirac_pixels16_sse2(uint8_t *dst, const uint8_t *src[5], int stride, int h)

{

    if (h&3)

        ff_avg_dirac_pixels16_c(dst, src, stride, h);

    else

    ff_avg_pixels16_sse2(dst, src[0], stride, h);

}
