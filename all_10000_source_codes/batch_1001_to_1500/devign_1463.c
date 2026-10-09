/* 
 * Benchmark Sample ID : devign_1463
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int libx265_encode_close(AVCodecContext *avctx)

{

    libx265Context *ctx = avctx->priv_data;



    av_frame_free(&avctx->coded_frame);



    ctx->api->param_free(ctx->params);



    if (ctx->encoder)

        ctx->api->encoder_close(ctx->encoder);



    return 0;

}
