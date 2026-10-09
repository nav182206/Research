/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6777
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a212a983c7f4faf06e600f32a165592dc5b6ae76
 */

static int push_single_pic(AVFilterLink *outlink)
{
    AVFilterContext *ctx = outlink->src;
    AVFilterLink *inlink = ctx->inputs[0];
    ShowWavesContext *showwaves = ctx->priv;
    int64_t n = 0, max_samples = showwaves->total_samples / outlink->w;
    AVFrame *out = showwaves->outpicref;
    struct frame_node *node;
    const int nb_channels = inlink->channels;
    const int x = 255 / (showwaves->split_channels ? 1 : nb_channels);
    const int ch_height = showwaves->split_channels ? outlink->h / nb_channels : outlink->h;
    const int linesize = out->linesize[0];
    int col = 0;
    int64_t *sum = showwaves->sum;
    av_log(ctx, AV_LOG_DEBUG, "Create frame averaging %"PRId64" samples per column\n", max_samples);
    memset(sum, 0, nb_channels);
    for (node = showwaves->audio_frames; node; node = node->next) {
        int i;
        const AVFrame *frame = node->frame;
        const int16_t *p = (const int16_t *)frame->data[0];
        for (i = 0; i < frame->nb_samples; i++) {
            int ch;
            for (ch = 0; ch < nb_channels; ch++)
                sum[ch] += abs(p[ch + i*nb_channels]) << 1;
            if (n++ == max_samples) {
                for (ch = 0; ch < nb_channels; ch++) {
                    int16_t sample = sum[ch] / max_samples;
                    uint8_t *buf = out->data[0] + col;
                    if (showwaves->split_channels)
                        buf += ch*ch_height*linesize;
                    av_assert0(col < outlink->w);
                    showwaves->draw_sample(buf, ch_height, linesize, sample, &showwaves->buf_idy[ch], x);
                    sum[ch] = 0;
                col++;
                n = 0;
    return push_frame(outlink);
