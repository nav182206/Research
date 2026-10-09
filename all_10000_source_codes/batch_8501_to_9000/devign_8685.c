/* 
 * Benchmark Sample ID : devign_8685
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int a64multi_close_encoder(AVCodecContext *avctx)

{

    A64Context *c = avctx->priv_data;

    av_frame_free(&avctx->coded_frame);

    av_free(c->mc_meta_charset);

    av_free(c->mc_best_cb);

    av_free(c->mc_charset);

    av_free(c->mc_charmap);

    av_free(c->mc_colram);

    return 0;

}
