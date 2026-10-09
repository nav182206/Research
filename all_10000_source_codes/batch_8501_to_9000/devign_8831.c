/* 
 * Benchmark Sample ID : devign_8831
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e8d4a7afbf40c0eb4bd70a6e7724d22ce7a6239
 */

static av_cold int g726_decode_init(AVCodecContext *avctx)

{

    G726Context* c = avctx->priv_data;



    if (avctx->sample_rate <= 0) {

        av_log(avctx, AV_LOG_ERROR, "Samplerate is invalid\n");

        return -1;

    }



    if(avctx->channels != 1){

        av_log(avctx, AV_LOG_ERROR, "Only mono is supported\n");

        return -1;

    }



    c->code_size = avctx->bits_per_coded_sample;

    if (c->code_size < 2 || c->code_size > 5) {

        av_log(avctx, AV_LOG_ERROR, "Invalid number of bits %d\n", c->code_size);

        return AVERROR(EINVAL);

    }

    g726_reset(c, c->code_size - 2);



    avctx->sample_fmt = AV_SAMPLE_FMT_S16;



    return 0;

}
