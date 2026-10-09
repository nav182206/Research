/* 
 * Benchmark Sample ID : devign_9949
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int ffv1_encode_close(AVCodecContext *avctx)

{

    av_frame_free(&avctx->coded_frame);

    ffv1_close(avctx);

    return 0;

}
