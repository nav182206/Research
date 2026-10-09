/* 
 * Benchmark Sample ID : devign_1008
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1fb46858c2498c67ae2d6775f7da29732e88fb8a
 */

static inline void scale_mv(AVSContext *h, int *d_x, int *d_y,

                            cavs_vector *src, int distp)

{

    int den = h->scale_den[src->ref];



    *d_x = (src->x * distp * den + 256 + (src->x >> 31)) >> 9;

    *d_y = (src->y * distp * den + 256 + (src->y >> 31)) >> 9;

}
