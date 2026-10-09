/* 
 * Benchmark Sample ID : devign_6158
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=53df079a730043cd0aa330c9aba7950034b1424f
 */

static av_cold int alac_decode_close(AVCodecContext *avctx)

{

    ALACContext *alac = avctx->priv_data;



    int chan;

    for (chan = 0; chan < alac->numchannels; chan++) {

        av_freep(&alac->predicterror_buffer[chan]);

        av_freep(&alac->outputsamples_buffer[chan]);

        av_freep(&alac->wasted_bits_buffer[chan]);

    }



    return 0;

}
