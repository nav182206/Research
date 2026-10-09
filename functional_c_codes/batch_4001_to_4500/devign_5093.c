/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5093
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0ac2d86c4758e1419934905b6c092910296aa16a
 */

static int dxva2_h264_start_frame(AVCodecContext *avctx,

                                  av_unused const uint8_t *buffer,

                                  av_unused uint32_t size)

{

    const H264Context *h = avctx->priv_data;

    AVDXVAContext *ctx = avctx->hwaccel_context;

    struct dxva2_picture_context *ctx_pic = h->cur_pic_ptr->hwaccel_picture_private;



    if (DXVA_CONTEXT_DECODER(avctx, ctx) == NULL ||

        DXVA_CONTEXT_CFG(avctx, ctx) == NULL ||

        DXVA_CONTEXT_COUNT(avctx, ctx) <= 0)

        return -1;

    assert(ctx_pic);



    /* Fill up DXVA_PicParams_H264 */

    fill_picture_parameters(avctx, ctx, h, &ctx_pic->pp);



    /* Fill up DXVA_Qmatrix_H264 */

    fill_scaling_lists(avctx, ctx, h, &ctx_pic->qm);



    ctx_pic->slice_count    = 0;

    ctx_pic->bitstream_size = 0;

    ctx_pic->bitstream      = NULL;

    return 0;

}
