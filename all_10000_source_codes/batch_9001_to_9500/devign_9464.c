/* 
 * Benchmark Sample ID : devign_9464
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2aab7c2dfaca4386c38e5d565cd2bf73096bcc86
 */

void ff_put_h264_qpel16_mc13_msa(uint8_t *dst, const uint8_t *src,

                                 ptrdiff_t stride)

{

    avc_luma_hv_qrt_16w_msa(src + stride - 2,

                            src - (stride * 2), stride, dst, stride, 16);

}
