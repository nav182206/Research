/* 
 * Benchmark Sample ID : devign_4662
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int v410_encode_init(AVCodecContext *avctx)

{

    if (avctx->width & 1) {

        av_log(avctx, AV_LOG_ERROR, "v410 requires even width.\n");

        return AVERROR_INVALIDDATA;

    }



    avctx->coded_frame = av_frame_alloc();



    if (!avctx->coded_frame) {

        av_log(avctx, AV_LOG_ERROR, "Could not allocate frame.\n");

        return AVERROR(ENOMEM);

    }



    return 0;

}
