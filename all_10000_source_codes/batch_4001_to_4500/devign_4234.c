/* 
 * Benchmark Sample ID : devign_4234
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int libopenjpeg_encode_close(AVCodecContext *avctx)

{

    LibOpenJPEGContext *ctx = avctx->priv_data;



    opj_destroy_compress(ctx->compress);

    opj_image_destroy(ctx->image);

    av_freep(&avctx->coded_frame);

    return 0;

}
