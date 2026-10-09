/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1420
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=77a4c8b959fa9bc6bcaa42b40a0b046cdf3fec38
 */

static av_cold int yop_decode_init(AVCodecContext *avctx)
{
    YopDecContext *s = avctx->priv_data;
    s->avctx = avctx;
    if (avctx->width & 1 || avctx->height & 1 ||
        av_image_check_size(avctx->width, avctx->height, 0, avctx) < 0) {
        av_log(avctx, AV_LOG_ERROR, "YOP has invalid dimensions\n");
        return -1;
    avctx->pix_fmt = PIX_FMT_PAL8;
    avcodec_get_frame_defaults(&s->frame);
    s->num_pal_colors = avctx->extradata[0];
    s->first_color[0] = avctx->extradata[1];
    s->first_color[1] = avctx->extradata[2];
    if (s->num_pal_colors + s->first_color[0] > 256 ||
        s->num_pal_colors + s->first_color[1] > 256) {
        av_log(avctx, AV_LOG_ERROR,
               "YOP: palette parameters invalid, header probably corrupt\n");
    return 0;
