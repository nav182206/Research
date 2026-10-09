/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3924
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f20b67173ca6a05b8c3dee02dad3b7243b96292b
 */

static inline void conv_to_int32(int32_t *loc, float *samples, int num, float norm)

{

    int i;

    for (i = 0; i < num; i++)

        loc[i] = ceilf((samples[i]/norm)*INT32_MAX);

}
