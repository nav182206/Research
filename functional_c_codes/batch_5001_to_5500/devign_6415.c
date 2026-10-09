/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6415
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=499b82f604616a6ce7de4bd8e15f4698702c1e6a
 */

static int vdadec_decode(AVCodecContext *avctx,
        void *data, int *got_frame, AVPacket *avpkt)
{
    VDADecoderContext *ctx = avctx->priv_data;
    AVFrame *pic = data;
    int ret;
    ret = ff_h264_decoder.decode(avctx, data, got_frame, avpkt);
    if (*got_frame) {
        AVBufferRef *buffer = pic->buf[0];
        VDABufferContext *context = av_buffer_get_opaque(buffer);
        CVPixelBufferRef cv_buffer = (CVPixelBufferRef)pic->data[3];
        CVPixelBufferLockBaseAddress(cv_buffer, 0);
        context->cv_buffer = cv_buffer;
        pic->format = ctx->pix_fmt;
        if (CVPixelBufferIsPlanar(cv_buffer)) {
            int i, count = CVPixelBufferGetPlaneCount(cv_buffer);
            av_assert0(count < 4);
            for (i = 0; i < count; i++) {
                pic->data[i] = CVPixelBufferGetBaseAddressOfPlane(cv_buffer, i);
                pic->linesize[i] = CVPixelBufferGetBytesPerRowOfPlane(cv_buffer, i);
            }
        } else {
            pic->data[0] = CVPixelBufferGetBaseAddress(cv_buffer);
            pic->linesize[0] = CVPixelBufferGetBytesPerRow(cv_buffer);
        }
    }
    avctx->pix_fmt = ctx->pix_fmt;
    return ret;
}
