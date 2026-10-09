/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1812
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1e6ee86d9254e8fd2158cc9a31d3be96b0809411
 */

static inline void scale_mv(AVSContext *h, int *d_x, int *d_y,

                            cavs_vector *src, int distp)

{

    int den = h->scale_den[FFMAX(src->ref, 0)];



    *d_x = (src->x * distp * den + 256 + FF_SIGNBIT(src->x)) >> 9;

    *d_y = (src->y * distp * den + 256 + FF_SIGNBIT(src->y)) >> 9;

}
