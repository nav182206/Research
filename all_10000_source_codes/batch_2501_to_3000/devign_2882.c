/* 
 * Benchmark Sample ID : devign_2882
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6fcd4f3c7255014eeb883385d32abc7442426314
 */

static av_cold int dfa_decode_init(AVCodecContext *avctx)

{

    DfaContext *s = avctx->priv_data;

    int ret;



    avctx->pix_fmt = PIX_FMT_PAL8;



    if ((ret = av_image_check_size(avctx->width, avctx->height, 0, avctx)) < 0)

        return ret;



    s->frame_buf = av_mallocz(avctx->width * avctx->height + AV_LZO_OUTPUT_PADDING);

    if (!s->frame_buf)

        return AVERROR(ENOMEM);



    return 0;

}
