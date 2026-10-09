/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2350
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=77742c75c5503c848447814a96f16abc6b9aa5f4
 */

static int dxva2_vp9_start_frame(AVCodecContext *avctx,

                                 av_unused const uint8_t *buffer,

                                 av_unused uint32_t size)

{

    const VP9SharedContext *h = avctx->priv_data;

    AVDXVAContext *ctx = avctx->hwaccel_context;

    struct vp9_dxva2_picture_context *ctx_pic = h->frames[CUR_FRAME].hwaccel_picture_private;



    if (DXVA_CONTEXT_DECODER(avctx, ctx) == NULL ||

        DXVA_CONTEXT_CFG(avctx, ctx) == NULL ||

        DXVA_CONTEXT_COUNT(avctx, ctx) <= 0)

        return -1;

    av_assert0(ctx_pic);



    /* Fill up DXVA_PicParams_VP9 */

    if (fill_picture_parameters(avctx, ctx, h, &ctx_pic->pp) < 0)

        return -1;



    ctx_pic->bitstream_size = 0;

    ctx_pic->bitstream      = NULL;

    return 0;

}
