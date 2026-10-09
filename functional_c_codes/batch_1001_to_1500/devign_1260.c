/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1260
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1181d93231e9b807965724587d363c1cfd5a1d0d
 */

void ff_avg_h264_qpel8_mc13_msa(uint8_t *dst, const uint8_t *src,

                                ptrdiff_t stride)

{

    avc_luma_hv_qrt_and_aver_dst_8x8_msa(src + stride - 2,

                                         src - (stride * 2),

                                         stride, dst, stride);

}
