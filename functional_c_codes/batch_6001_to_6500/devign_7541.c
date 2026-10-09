/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7541
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a150bad4062a29fc11b32117bc1ade38115cd95b
 */

AVFilterBufferRef *avfilter_get_audio_buffer_ref_from_frame(const AVFrame *frame,

                                                            int perms)

{

    AVFilterBufferRef *samplesref =

        avfilter_get_audio_buffer_ref_from_arrays((uint8_t **)frame->data, frame->linesize[0], perms,

                                                  frame->nb_samples, frame->format,

                                                  av_frame_get_channel_layout(frame));

    if (!samplesref)

        return NULL;

    avfilter_copy_frame_props(samplesref, frame);

    return samplesref;

}
