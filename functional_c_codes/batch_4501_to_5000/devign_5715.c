/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5715
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=973b1a6b9070e2bf17d17568cbaf4043ce931f51
 */

static av_cold int vdadec_close(AVCodecContext *avctx)

{

    VDADecoderContext *ctx = avctx->priv_data;

    /* release buffers and decoder */

    ff_vda_destroy_decoder(&ctx->vda_ctx);

    /* close H.264 decoder */

    if (ctx->h264_initialized)

        ff_h264_decoder.close(avctx);

    return 0;

}
