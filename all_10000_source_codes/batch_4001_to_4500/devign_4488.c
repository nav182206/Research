/* 
 * Benchmark Sample ID : devign_4488
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1af5f60f6aafa5f2653e7ea7cd054b0a4f31c103
 */

static void horizontal_filter(unsigned char *first_pixel, int stride,

    int *bounding_values)

{

    unsigned char *end;

    int filter_value;



    for (end= first_pixel + 8*stride; first_pixel < end; first_pixel += stride) {

        filter_value =

            (first_pixel[-2] - first_pixel[ 1])

         +3*(first_pixel[ 0] - first_pixel[-1]);

        filter_value = bounding_values[(filter_value + 4) >> 3];

        first_pixel[-1] = clip_uint8(first_pixel[-1] + filter_value);

        first_pixel[ 0] = clip_uint8(first_pixel[ 0] - filter_value);

    }

}
