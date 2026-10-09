/* 
 * Benchmark Sample ID : devign_4459
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2df0c32ea12ddfa72ba88309812bfb13b674130f
 */

static av_cold int amr_wb_encode_init(AVCodecContext *avctx)

{

    AMRWBContext *s = avctx->priv_data;



    if (avctx->sample_rate != 16000) {

        av_log(avctx, AV_LOG_ERROR, "Only 16000Hz sample rate supported\n");

        return AVERROR(ENOSYS);

    }



    if (avctx->channels != 1) {

        av_log(avctx, AV_LOG_ERROR, "Only mono supported\n");

        return AVERROR(ENOSYS);

    }



    s->mode            = get_wb_bitrate_mode(avctx->bit_rate, avctx);

    s->last_bitrate    = avctx->bit_rate;



    avctx->frame_size  = 320;

    avctx->delay       =  80;



    s->state     = E_IF_init();



    return 0;

}
