/* 
 * Benchmark Sample ID : devign_8490
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c10350358da58600884292c08a8690289b81de29
 */

static void gif_copy_img_rect(const uint32_t *src, uint32_t *dst,

                              int linesize, int l, int t, int w, int h)

{

    const int y_start = t * linesize;

    const uint32_t *src_px, *src_pr,

                   *src_py = src + y_start,

                   *dst_py = dst + y_start;

    const uint32_t *src_pb = src_py + t * linesize;

    uint32_t *dst_px;



    for (; src_py < src_pb; src_py += linesize, dst_py += linesize) {

        src_px = src_py + l;

        dst_px = (uint32_t *)dst_py + l;

        src_pr = src_px + w;



        for (; src_px < src_pr; src_px++, dst_px++)

            *dst_px = *src_px;

    }

}
