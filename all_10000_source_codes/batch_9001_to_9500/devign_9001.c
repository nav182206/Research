/* 
 * Benchmark Sample ID : devign_9001
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=143685a42bbc8861b626457ce4cb8b1ce4b0c436
 */

static av_cold int ffat_close_encoder(AVCodecContext *avctx)

{

    ATDecodeContext *at = avctx->priv_data;

    AudioConverterDispose(at->converter);

    av_frame_unref(&at->new_in_frame);

    av_frame_unref(&at->in_frame);

    ff_af_queue_close(&at->afq);

    return 0;

}
