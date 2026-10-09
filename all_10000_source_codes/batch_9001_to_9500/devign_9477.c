/* 
 * Benchmark Sample ID : devign_9477
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2aab7c2dfaca4386c38e5d565cd2bf73096bcc86
 */

void ff_put_h264_qpel4_mc11_msa(uint8_t *dst, const uint8_t *src,

                                ptrdiff_t stride)

{

    avc_luma_hv_qrt_4w_msa(src - 2, src - (stride * 2), stride, dst, stride, 4);

}
