/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4539
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a1e5be5c1a0c98206a1ae034d278702f5c8ef2a3
 */

static void pulse_get_output_timestamp(AVFormatContext *h, int stream, int64_t *dts, int64_t *wall)

{

    PulseData *s = h->priv_data;

    pa_usec_t latency;

    int neg;

    pa_threaded_mainloop_lock(s->mainloop);

    pa_stream_get_latency(s->stream, &latency, &neg);

    pa_threaded_mainloop_unlock(s->mainloop);

    *wall = av_gettime();

    *dts = s->timestamp - (neg ? -latency : latency);

}
