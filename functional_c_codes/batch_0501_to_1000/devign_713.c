/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_713
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32c3047cac9294bb56d23c89a40a22409db5cc70
 */

static int rpza_decode_init(AVCodecContext *avctx)

{

    RpzaContext *s = avctx->priv_data;



    s->avctx = avctx;

    avctx->pix_fmt = PIX_FMT_RGB555;

    dsputil_init(&s->dsp, avctx);



    s->frame.data[0] = NULL;



    return 0;

}
