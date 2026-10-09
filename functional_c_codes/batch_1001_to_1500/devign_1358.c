/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1358
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6ed3565f08abf3b1c2a1d2d7fac768b18753530c
 */

static av_cold int v410_decode_init(AVCodecContext *avctx)

{

    avctx->pix_fmt             = PIX_FMT_YUV444P10;

    avctx->bits_per_raw_sample = 10;



    if (avctx->width & 1) {

        av_log(avctx, AV_LOG_ERROR, "v410 requires width to be even.\n");

        return AVERROR_INVALIDDATA;

    }



    avctx->coded_frame = avcodec_alloc_frame();



    if (!avctx->coded_frame) {

        av_log(avctx, AV_LOG_ERROR, "Could not allocate frame.\n");

        return AVERROR(ENOMEM);

    }



    return 0;

}
