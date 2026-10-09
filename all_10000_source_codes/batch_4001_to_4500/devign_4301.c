/* 
 * Benchmark Sample ID : devign_4301
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9076a6a943f7855756222181698aba78d3773d8f
 */

static void print_samplesref(AVFilterBufferRef *samplesref)

{

    const AVFilterBufferRefAudioProps *props = samplesref->audio;

    const int n = props->nb_samples * av_get_channel_layout_nb_channels(props->channel_layout);

    const uint16_t *p     = (uint16_t*)samplesref->data[0];

    const uint16_t *p_end = p + n;



    while (p < p_end) {

        fputc(*p    & 0xff, stdout);

        fputc(*p>>8 & 0xff, stdout);

        p++;

    }

    fflush(stdout);

}
