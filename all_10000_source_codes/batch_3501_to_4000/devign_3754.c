/* 
 * Benchmark Sample ID : devign_3754
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=28f9ab7029bd1a02f659995919f899f84ee7361b
 */

void ff_vp3_h_loop_filter_c(uint8_t *first_pixel, int stride, int *bounding_values)

{

    unsigned char *end;

    int filter_value;



    for (end= first_pixel + 8*stride; first_pixel != end; first_pixel += stride) {

        filter_value =

            (first_pixel[-2] - first_pixel[ 1])

         +3*(first_pixel[ 0] - first_pixel[-1]);

        filter_value = bounding_values[(filter_value + 4) >> 3];

        first_pixel[-1] = av_clip_uint8(first_pixel[-1] + filter_value);

        first_pixel[ 0] = av_clip_uint8(first_pixel[ 0] - filter_value);

    }

}
