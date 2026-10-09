/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1076
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=085ca7dcdbf9ab6c23e3a5397b1f6d4aa23f763d
 */

static int teletext_close_decoder(AVCodecContext *avctx)

{

    TeletextContext *ctx = avctx->priv_data;



    av_dlog(avctx, "lines_total=%u\n", ctx->lines_processed);

    while (ctx->nb_pages)

        subtitle_rect_free(&ctx->pages[--ctx->nb_pages].sub_rect);

    av_freep(&ctx->pages);



    vbi_dvb_demux_delete(ctx->dx);

    vbi_decoder_delete(ctx->vbi);

    ctx->dx = NULL;

    ctx->vbi = NULL;

    ctx->pts = AV_NOPTS_VALUE;

    return 0;

}
