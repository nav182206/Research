/* 
 * Benchmark Sample ID : devign_9364
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=662234a9a22f1cd0f0ac83b8bb1ffadedca90c0a
 */

void ff_put_h264_qpel16_mc02_msa(uint8_t *dst, const uint8_t *src,

                                 ptrdiff_t stride)

{

    avc_luma_vt_16w_msa(src - (stride * 2), stride, dst, stride, 16);

}
