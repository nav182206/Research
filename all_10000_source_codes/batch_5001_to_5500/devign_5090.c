/* 
 * Benchmark Sample ID : devign_5090
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ab28108a361196134704071b7b34c42fc7d747c7
 */

static int dxva2_mpeg2_start_frame(AVCodecContext *avctx,

                                   av_unused const uint8_t *buffer,

                                   av_unused uint32_t size)

{

    const struct MpegEncContext *s = avctx->priv_data;

    AVDXVAContext *ctx = avctx->hwaccel_context;

    struct dxva2_picture_context *ctx_pic =

        s->current_picture_ptr->hwaccel_picture_private;



    if (!DXVA_CONTEXT_VALID(avctx, ctx))

        return -1;

    assert(ctx_pic);



    fill_picture_parameters(avctx, ctx, s, &ctx_pic->pp);

    fill_quantization_matrices(avctx, ctx, s, &ctx_pic->qm);



    ctx_pic->slice_count    = 0;

    ctx_pic->bitstream_size = 0;

    ctx_pic->bitstream      = NULL;

    return 0;

}
