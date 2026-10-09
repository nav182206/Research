/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2755
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0058584580b87feb47898e60e4b80c7f425882ad
 */

static inline void downmix_dualmono_to_stereo(float *samples)

{

    int i;

    float tmp;



    for (i = 0; i < 256; i++) {

        tmp = samples[i] + samples[i + 256];

        samples[i] = samples[i + 256] = tmp;

    }

}
