/* 
 * Benchmark Sample ID : devign_6213
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6796a1dd8c14843b77925cb83a3ef88706ae1dd0
 */

void ff_put_h264_qpel16_mc01_msa(uint8_t *dst, const uint8_t *src,

                                 ptrdiff_t stride)

{

    avc_luma_vt_qrt_16w_msa(src - (stride * 2), stride, dst, stride, 16, 0);

}
