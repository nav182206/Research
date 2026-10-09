/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8134
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7888ae8266d8f721cc443fe3aa627d350ca01204
 */

static av_cold int cfhd_decode_init(AVCodecContext *avctx)

{

    CFHDContext *s = avctx->priv_data;



    avctx->bits_per_raw_sample = 10;

    s->avctx                   = avctx;

    avctx->width               = 0;

    avctx->height              = 0;



    return ff_cfhd_init_vlcs(s);

}
