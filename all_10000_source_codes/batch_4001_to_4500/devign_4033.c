/* 
 * Benchmark Sample ID : devign_4033
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2856332719d8ec182523f7793bb0517aaac68e73
 */

static int vda_h264_uninit(AVCodecContext *avctx)

{

    VDAContext *vda = avctx->internal->hwaccel_priv_data;

    av_freep(&vda->bitstream);

    if (vda->frame)

        CVPixelBufferRelease(vda->frame);

    return 0;

}
