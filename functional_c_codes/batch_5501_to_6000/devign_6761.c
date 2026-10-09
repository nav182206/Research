/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6761
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=27bcf55f459e038e81f09c17e72e6d44898b9015
 */

int av_vsrc_buffer_add_frame(AVFilterContext *buffer_src, const AVFrame *frame)

{

    int ret;

    AVFilterBufferRef *picref =

        avfilter_get_video_buffer_ref_from_frame(frame, AV_PERM_WRITE);

    if (!picref)

        return AVERROR(ENOMEM);

    ret = av_vsrc_buffer_add_video_buffer_ref(buffer_src, picref);

    picref->buf->data[0] = NULL;

    avfilter_unref_buffer(picref);



    return ret;

}
