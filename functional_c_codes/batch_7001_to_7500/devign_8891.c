/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8891
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9f4dc52a0fe3edb93f153cf13e750f7c46243d1
 */

static av_cold int prores_encode_close(AVCodecContext *avctx)

{

    ProresContext* ctx = avctx->priv_data;

    av_freep(&avctx->coded_frame);

    av_free(ctx->fill_y);

    av_free(ctx->fill_u);

    av_free(ctx->fill_v);



    return 0;

}
