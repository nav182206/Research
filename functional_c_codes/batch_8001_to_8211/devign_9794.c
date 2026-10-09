/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9794
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2cbe6bac0337939f023bd1c37a9c455e6d535f3a
 */

static void blend_frames_c(BLEND_FUNC_PARAMS)

{

    int line, pixel;

    for (line = 0; line < height; line++) {

        for (pixel = 0; pixel < width; pixel++) {

            // integer version of (src1 * factor1) + (src2 * factor2) + 0.5

            // 0.5 is for rounding

            // 128 is the integer representation of 0.5 << 8

            dst[pixel] = ((src1[pixel] * factor1) + (src2[pixel] * factor2) + 128) >> 8;

        }

        src1 += src1_linesize;

        src2 += src2_linesize;

        dst  += dst_linesize;

    }

}
