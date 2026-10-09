/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2649
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=80a5d05108cb218e8cd2e25c6621a3bfef0a832e
 */

static av_cold int vaapi_encode_h264_init(AVCodecContext *avctx)

{

    return ff_vaapi_encode_init(avctx, &vaapi_encode_type_h264);

}
