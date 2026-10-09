/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5611
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8501c098687bbf551a2f1cdef80ee653fdfff6ac
 */

static int output_frame(AVFilterLink *outlink, int nb_samples)

{

    AVFilterContext *ctx = outlink->src;

    MixContext      *s = ctx->priv;

    AVFilterBufferRef *out_buf, *in_buf;

    int i;



    calculate_scales(s, nb_samples);



    out_buf = ff_get_audio_buffer(outlink, AV_PERM_WRITE, nb_samples);

    if (!out_buf)

        return AVERROR(ENOMEM);



    in_buf = ff_get_audio_buffer(outlink, AV_PERM_WRITE, nb_samples);

    if (!in_buf)

        return AVERROR(ENOMEM);



    for (i = 0; i < s->nb_inputs; i++) {

        if (s->input_state[i] == INPUT_ON) {

            int planes, plane_size, p;



            av_audio_fifo_read(s->fifos[i], (void **)in_buf->extended_data,

                               nb_samples);



            planes     = s->planar ? s->nb_channels : 1;

            plane_size = nb_samples * (s->planar ? 1 : s->nb_channels);

            plane_size = FFALIGN(plane_size, 16);



            for (p = 0; p < planes; p++) {

                s->fdsp.vector_fmac_scalar((float *)out_buf->extended_data[p],

                                           (float *) in_buf->extended_data[p],

                                           s->input_scale[i], plane_size);

            }

        }

    }

    avfilter_unref_buffer(in_buf);



    out_buf->pts = s->next_pts;

    if (s->next_pts != AV_NOPTS_VALUE)

        s->next_pts += nb_samples;



    return ff_filter_samples(outlink, out_buf);

}
