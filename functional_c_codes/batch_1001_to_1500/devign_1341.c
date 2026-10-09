/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1341
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ebcf7c3227906382205141beb2d0467f245472d1
 */

int ff_cmap_read_palette(AVCodecContext *avctx, uint32_t *pal)

{

    int count, i;



    if (avctx->bits_per_coded_sample > 8) {

        av_log(avctx, AV_LOG_ERROR, "bit_per_coded_sample > 8 not supported\n");

        return AVERROR_INVALIDDATA;

    }



    count = 1 << avctx->bits_per_coded_sample;

    if (avctx->extradata_size < count * 3) {

        av_log(avctx, AV_LOG_ERROR, "palette data underflow\n");

        return AVERROR_INVALIDDATA;

    }

    for (i=0; i < count; i++) {

        pal[i] = 0xFF000000 | AV_RB24( avctx->extradata + i*3 );

    }

    return 0;

}
