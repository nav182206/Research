/* 
 * Benchmark Sample ID : devign_6591
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9321e93502810e4a3fcaf87bac156dba2fe3b477
 */

static void gif_copy_img_rect(const uint32_t *src, uint32_t *dst,

                              int linesize, int l, int t, int w, int h)

{

    const int y_start = t * linesize;

    const uint32_t *src_px, *src_pr,

                   *src_py = src + y_start,

                   *dst_py = dst + y_start;

    const uint32_t *src_pb = src_py + (t + h) * linesize;

    uint32_t *dst_px;



    for (; src_py < src_pb; src_py += linesize, dst_py += linesize) {

        src_px = src_py + l;

        dst_px = (uint32_t *)dst_py + l;

        src_pr = src_px + w;



        for (; src_px < src_pr; src_px++, dst_px++)

            *dst_px = *src_px;

    }

}
