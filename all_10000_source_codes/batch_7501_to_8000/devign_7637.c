/* 
 * Benchmark Sample ID : devign_7637
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1181d93231e9b807965724587d363c1cfd5a1d0d
 */

void ff_avg_h264_qpel16_mc31_msa(uint8_t *dst, const uint8_t *src,

                                 ptrdiff_t stride)

{

    avc_luma_hv_qrt_and_aver_dst_16x16_msa(src - 2,

                                           src - (stride * 2) +

                                           sizeof(uint8_t), stride,

                                           dst, stride);

}
