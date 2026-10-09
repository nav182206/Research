/* 
 * Benchmark Sample ID : devign_8283
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c7384664ba0cbb12d882effafbc6d321ae706cff
 */

static av_cold int avs_decode_init(AVCodecContext * avctx)

{

    AvsContext *s = avctx->priv_data;



    s->frame = av_frame_alloc();

    if (!s->frame)

        return AVERROR(ENOMEM);



    avctx->pix_fmt = AV_PIX_FMT_PAL8;

    ff_set_dimensions(avctx, 318, 198);



    return 0;

}
