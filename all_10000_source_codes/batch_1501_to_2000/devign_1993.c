/* 
 * Benchmark Sample ID : devign_1993
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6260ab60a80fd8baebf79f9ce9299b0db72333b5
 */

static void blend_image_rgba_pm(AVFilterContext *ctx, AVFrame *dst, const AVFrame *src, int x, int y)

{

    blend_image_packed_rgb(ctx, dst, src, 1, x, y, 1);

}
