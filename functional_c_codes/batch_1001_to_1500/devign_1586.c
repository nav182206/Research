/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1586
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=34c52005605d68f7cd1957b169b6732c7d2447d9
 */

static float **alloc_audio_arrays(int channels, int frame_size)

{

    float **audio = av_mallocz_array(channels, sizeof(float *));

    if (!audio)

        return NULL;



    for (int ch = 0; ch < channels; ch++) {

        audio[ch] = av_mallocz_array(frame_size, sizeof(float));

        if (!audio[ch]) {

            // alloc has failed, free everything allocated thus far

            for (ch--; ch >= 0; ch--)

                av_free(audio[ch]);

            av_free(audio);

            return NULL;

        }

    }



    return audio;

}
