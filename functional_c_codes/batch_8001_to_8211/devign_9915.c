/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9915
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72dbc610be3272ba36603f78a39cc2d2d8fe0cc3
 */

void ff_avg_h264_qpel16_mc02_msa(uint8_t *dst, const uint8_t *src,

                                 ptrdiff_t stride)

{

    avc_luma_vt_and_aver_dst_16x16_msa(src - (stride * 2), stride, dst, stride);

}
