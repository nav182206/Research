/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5236
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a8bdf2405c6027f45a899eaaa6ba74e97c1c2701
 */

static av_cold int pcm_encode_init(AVCodecContext *avctx)

{

    avctx->frame_size = 0;

    switch(avctx->codec->id) {

    case CODEC_ID_PCM_ALAW:

        pcm_alaw_tableinit();

        break;

    case CODEC_ID_PCM_MULAW:

        pcm_ulaw_tableinit();

        break;

    default:

        break;

    }



    avctx->bits_per_coded_sample = av_get_bits_per_sample(avctx->codec->id);

    avctx->block_align = avctx->channels * avctx->bits_per_coded_sample/8;

    avctx->coded_frame= avcodec_alloc_frame();





    return 0;

}
