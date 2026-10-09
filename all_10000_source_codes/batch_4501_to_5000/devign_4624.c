/* 
 * Benchmark Sample ID : devign_4624
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f6774f905fb3cfdc319523ac640be30b14c1bc55
 */

int ff_vdpau_mpeg_end_frame(AVCodecContext *avctx)

{

    AVVDPAUContext *hwctx = avctx->hwaccel_context;

    MpegEncContext *s = avctx->priv_data;

    Picture *pic = s->current_picture_ptr;

    struct vdpau_picture_context *pic_ctx = pic->hwaccel_picture_private;

    VdpVideoSurface surf = ff_vdpau_get_surface_id(&pic->f);



    hwctx->render(hwctx->decoder, surf, (void *)&pic_ctx->info,

                  pic_ctx->bitstream_buffers_used, pic_ctx->bitstream_buffers);



    ff_mpeg_draw_horiz_band(s, 0, s->avctx->height);

    av_freep(&pic_ctx->bitstream_buffers);



    return 0;

}
