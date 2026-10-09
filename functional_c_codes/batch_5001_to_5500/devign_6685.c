/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6685
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a84f0e8d8f293df3c535f9b893730a835bed6520
 */

av_cold int ff_vp8_decode_free(AVCodecContext *avctx)
{
    VP8Context *s = avctx->priv_data;
    int i;
    vp8_decode_flush_impl(avctx, 1);
    for (i = 0; i < FF_ARRAY_ELEMS(s->frames); i++)
        av_frame_free(&s->frames[i].tf.f);
}
