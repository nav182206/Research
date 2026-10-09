/* 
 * Benchmark Sample ID : devign_7939
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ee715f49a06bf3898246d01b056284a9bb1bcbb9
 */

static av_cold int dfa_decode_init(AVCodecContext *avctx)
{
    DfaContext *s = avctx->priv_data;
    avctx->pix_fmt = PIX_FMT_PAL8;
    s->frame_buf = av_mallocz(avctx->width * avctx->height + AV_LZO_OUTPUT_PADDING);
    if (!s->frame_buf)
        return AVERROR(ENOMEM);
    return 0;
}
