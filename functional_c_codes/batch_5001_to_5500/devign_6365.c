/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6365
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cc276c85d15272df6e44fb3252657a43cbd49555
 */

AVFilterBufferRef *avfilter_get_audio_buffer(AVFilterLink *link, int perms,

                                             enum AVSampleFormat sample_fmt, int size,

                                             int64_t channel_layout, int planar)

{

    AVFilterBufferRef *ret = NULL;



    if (link->dstpad->get_audio_buffer)

        ret = link->dstpad->get_audio_buffer(link, perms, sample_fmt, size, channel_layout, planar);



    if (!ret)

        ret = avfilter_default_get_audio_buffer(link, perms, sample_fmt, size, channel_layout, planar);



    if (ret)

        ret->type = AVMEDIA_TYPE_AUDIO;



    return ret;

}
