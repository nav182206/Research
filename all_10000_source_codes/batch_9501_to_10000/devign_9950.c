/* 
 * Benchmark Sample ID : devign_9950
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f20b67173ca6a05b8c3dee02dad3b7243b96292b
 */

static inline void conv_to_float(float *arr, int32_t *cof, int num)

{

    int i;

    for (i = 0; i < num; i++)

        arr[i] = (float)cof[i]/INT32_MAX;

}
