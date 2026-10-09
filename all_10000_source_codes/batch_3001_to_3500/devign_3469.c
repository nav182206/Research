/* 
 * Benchmark Sample ID : devign_3469
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e549933a270dd2cfc36f2cf9bb6b29acf3dc6d08
 */

void ff_put_h264_qpel16_mc22_msa(uint8_t *dst, const uint8_t *src,

                                 ptrdiff_t stride)

{

    avc_luma_mid_16w_msa(src - (2 * stride) - 2, stride, dst, stride, 16);

}
