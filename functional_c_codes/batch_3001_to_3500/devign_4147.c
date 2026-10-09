/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4147
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=973b1a6b9070e2bf17d17568cbaf4043ce931f51
 */

static void vdadec_flush(AVCodecContext *avctx)

{

    return ff_h264_decoder.flush(avctx);

}
