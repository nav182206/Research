/* 
 * Benchmark Sample ID : devign_5332
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e7e59409294af9caa63808e56c5cc824c98b4fc
 */

static inline int is_yuv_planar(PixFmtInfo *ps)

{

    return (ps->color_type == FF_COLOR_YUV ||

            ps->color_type == FF_COLOR_YUV_JPEG) && !ps->is_packed;

}
