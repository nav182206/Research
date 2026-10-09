/* 
 * Benchmark Sample ID : devign_1250
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6796a1dd8c14843b77925cb83a3ef88706ae1dd0
 */

void ff_put_h264_qpel8_mc20_msa(uint8_t *dst, const uint8_t *src,

                                ptrdiff_t stride)

{

    avc_luma_hz_8w_msa(src - 2, stride, dst, stride, 8);

}
