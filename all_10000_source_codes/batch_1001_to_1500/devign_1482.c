/* 
 * Benchmark Sample ID : devign_1482
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0105ed551cb9610c62b6920a301125781e1161a0
 */

void ff_avg_h264_qpel8_mc00_msa(uint8_t *dst, const uint8_t *src,

                                ptrdiff_t stride)

{

    avg_width8_msa(src, stride, dst, stride, 8);

}
