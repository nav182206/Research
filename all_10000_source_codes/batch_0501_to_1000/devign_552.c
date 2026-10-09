/* 
 * Benchmark Sample ID : devign_552
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dd561441b1e849df7d8681c6f32af82d4088dafd
 */

static void h264_h_loop_filter_luma_intra_c(uint8_t *pix, int stride, int alpha, int beta)

{

    h264_loop_filter_luma_intra_c(pix, 1, stride, alpha, beta);

}
