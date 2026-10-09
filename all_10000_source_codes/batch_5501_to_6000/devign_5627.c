/* 
 * Benchmark Sample ID : devign_5627
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8aba7968dd604aae91ee42cbce0be3dad7dceb30
 */

static av_cold int vcr1_decode_init(AVCodecContext *avctx)
{
    avctx->pix_fmt = AV_PIX_FMT_YUV410P;
    return 0;
