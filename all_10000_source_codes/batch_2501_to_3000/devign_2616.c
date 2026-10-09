/* 
 * Benchmark Sample ID : devign_2616
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int bmp_encode_init(AVCodecContext *avctx){

    switch (avctx->pix_fmt) {

    case AV_PIX_FMT_BGR24:

        avctx->bits_per_coded_sample = 24;

        break;

    case AV_PIX_FMT_RGB555:

    case AV_PIX_FMT_RGB565:

    case AV_PIX_FMT_RGB444:

        avctx->bits_per_coded_sample = 16;

        break;

    case AV_PIX_FMT_RGB8:

    case AV_PIX_FMT_BGR8:

    case AV_PIX_FMT_RGB4_BYTE:

    case AV_PIX_FMT_BGR4_BYTE:

    case AV_PIX_FMT_GRAY8:

    case AV_PIX_FMT_PAL8:

        avctx->bits_per_coded_sample = 8;

        break;

    case AV_PIX_FMT_MONOBLACK:

        avctx->bits_per_coded_sample = 1;

        break;

    default:

        av_log(avctx, AV_LOG_INFO, "unsupported pixel format\n");

        return -1;

    }



    avctx->coded_frame = av_frame_alloc();

    if (!avctx->coded_frame)

        return AVERROR(ENOMEM);



    return 0;

}
