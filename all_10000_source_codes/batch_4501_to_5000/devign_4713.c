/* 
 * Benchmark Sample ID : devign_4713
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b5da07d4340a8e8e40dcd1900977a76ff31fbb84
 */

void ff_put_h264_qpel16_mc30_msa(uint8_t *dst, const uint8_t *src,

                                 ptrdiff_t stride)

{

    avc_luma_hz_qrt_16w_msa(src - 2, stride, dst, stride, 16, 1);

}
