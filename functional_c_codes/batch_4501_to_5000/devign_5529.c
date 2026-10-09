/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5529
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0058584580b87feb47898e60e4b80c7f425882ad
 */

static inline void downmix_3f_2r_to_dolby(float *samples)

{

    int i;



    for (i = 0; i < 256; i++) {

        samples[i] += (samples[i + 256] - samples[i + 768]);

        samples[i + 256] = (samples[i + 512] + samples[i + 1024]);

        samples[i + 512] = samples[i + 768] = samples[i + 1024] = 0;

    }

}
