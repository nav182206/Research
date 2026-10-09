/* 
 * Benchmark Sample ID : devign_6330
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int encode_init_ls(AVCodecContext *ctx)

{

    ctx->coded_frame = av_frame_alloc();

    if (!ctx->coded_frame)

        return AVERROR(ENOMEM);



    ctx->coded_frame->pict_type = AV_PICTURE_TYPE_I;

    ctx->coded_frame->key_frame = 1;



    if (ctx->pix_fmt != AV_PIX_FMT_GRAY8  &&

        ctx->pix_fmt != AV_PIX_FMT_GRAY16 &&

        ctx->pix_fmt != AV_PIX_FMT_RGB24  &&

        ctx->pix_fmt != AV_PIX_FMT_BGR24) {

        av_log(ctx, AV_LOG_ERROR,

               "Only grayscale and RGB24/BGR24 images are supported\n");

        return -1;

    }

    return 0;

}
