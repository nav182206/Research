/* 
 * Benchmark Sample ID : devign_9031
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c6a905b91d935f78f5c33f6ce2dbe294b3353b77
 */

static av_cold int dnxhd_decode_init(AVCodecContext *avctx)

{

    DNXHDContext *ctx = avctx->priv_data;



    ctx->avctx = avctx;

    ctx->cid = -1;

    avctx->colorspace = AVCOL_SPC_BT709;



    avctx->coded_width  = FFALIGN(avctx->width,  16);

    avctx->coded_height = FFALIGN(avctx->height, 16);



    ctx->rows = av_mallocz_array(avctx->thread_count, sizeof(RowContext));

    if (!ctx->rows)

        return AVERROR(ENOMEM);



    return 0;

}
