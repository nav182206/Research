/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4644
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3303926c2f06841270281e7f5210c0c94292e089
 */

static int has_codec_parameters(AVCodecContext *enc)

{

    int val;

    switch(enc->codec_type) {

    case CODEC_TYPE_AUDIO:

        val = enc->sample_rate;

        break;

    case CODEC_TYPE_VIDEO:

        val = enc->width && enc->pix_fmt != PIX_FMT_NONE;

        break;

    default:

        val = 1;

        break;

    }

    return (val != 0);

}
