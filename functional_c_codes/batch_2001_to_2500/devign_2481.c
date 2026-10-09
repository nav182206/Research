/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2481
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6ac9afd16e385fc450c58b8a3fb44baa99ea4af9
 */

audio_get_output_timestamp(AVFormatContext *s1, int stream,

    int64_t *dts, int64_t *wall)

{

    AlsaData *s  = s1->priv_data;

    snd_pcm_sframes_t delay = 0;

    *wall = av_gettime();

    snd_pcm_delay(s->h, &delay);

    *dts = s1->streams[0]->cur_dts - delay;

}
