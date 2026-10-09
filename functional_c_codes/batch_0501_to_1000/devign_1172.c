/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1172
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eb5b0422b595d488f5c2f2a37a62cd46dfbb6aa7
 */

static int g726_init(AVCodecContext * avctx)

{

    AVG726Context* c = (AVG726Context*)avctx->priv_data;

    

    if (avctx->sample_rate != 8000 || avctx->channels != 1 ||

        (avctx->bit_rate != 16000 && avctx->bit_rate != 24000 &&

	 avctx->bit_rate != 32000 && avctx->bit_rate != 40000)) {

        av_log(avctx, AV_LOG_ERROR, "G726: unsupported audio format\n");

	return -1;

    }

    g726_reset(&c->c, avctx->bit_rate);

    c->code_size = c->c.tbls->bits;

    c->bit_buffer = 0;

    c->bits_left = 0;



    return 0;

}
