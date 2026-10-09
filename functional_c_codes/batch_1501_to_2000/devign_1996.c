/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1996
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bcd7bf7eeb09a395cc01698842d1b8be9af483fc
 */

void ff_weight_h264_pixels8_8_msa(uint8_t *src, int stride,

                                  int height, int log2_denom,

                                  int weight_src, int offset)

{

    avc_wgt_8width_msa(src, stride,

                       height, log2_denom, weight_src, offset);

}
