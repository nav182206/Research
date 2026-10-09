/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1506
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int vp8_free(AVCodecContext *avctx)

{

    VP8Context *ctx = avctx->priv_data;



    vpx_codec_destroy(&ctx->encoder);

    av_freep(&ctx->twopass_stats.buf);

    av_freep(&avctx->coded_frame);

    av_freep(&avctx->stats_out);

    free_frame_list(ctx->coded_frame_list);

    return 0;

}
