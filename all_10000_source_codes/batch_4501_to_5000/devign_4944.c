/* 
 * Benchmark Sample ID : devign_4944
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f4e593f7b51f7cb30986186c187cff939c82d86d
 */

static av_cold int ffat_close_decoder(AVCodecContext *avctx)

{

    ATDecodeContext *at = avctx->priv_data;

    if (at->converter)

        AudioConverterDispose(at->converter);

    av_packet_unref(&at->new_in_pkt);

    av_packet_unref(&at->in_pkt);

    av_free(at->decoded_data);

    av_free(at->extradata);

    return 0;

}
