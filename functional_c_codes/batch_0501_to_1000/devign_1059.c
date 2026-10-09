/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1059
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0058584580b87feb47898e60e4b80c7f425882ad
 */

static inline void float_to_int (float * _f, int16_t * s16, int samples)

{

    int32_t * f = (int32_t *) _f;       // XXX assumes IEEE float format

    int i;



    for (i = 0; i < samples; i++) {

        s16[i] = blah (f[i]);

    }

}
