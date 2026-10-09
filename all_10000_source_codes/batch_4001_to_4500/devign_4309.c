/* 
 * Benchmark Sample ID : devign_4309
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1adad3cca407f493c3637e20ecd4f7124e69212
 */

static inline void RENAME(yv12toyuy2)(const uint8_t *ysrc, const uint8_t *usrc, const uint8_t *vsrc, uint8_t *dst,

                                      long width, long height,

                                      long lumStride, long chromStride, long dstStride)

{

    //FIXME interpolate chroma

    RENAME(yuvPlanartoyuy2)(ysrc, usrc, vsrc, dst, width, height, lumStride, chromStride, dstStride, 2);

}
