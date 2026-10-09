/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8828
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dd561441b1e849df7d8681c6f32af82d4088dafd
 */

static void h264_h_loop_filter_luma_c(uint8_t *pix, int stride, int alpha, int beta, int8_t *tc0)

{

    h264_loop_filter_luma_c(pix, 1, stride, alpha, beta, tc0);

}
