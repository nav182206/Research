/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7395
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0c2aaa882d124f05b7bf0a4a4abba3293f4d6d84
 */

static int encode_end(AVCodecContext *avctx)

{

    FFV1Context *s = avctx->priv_data;



    common_end(s);



    return 0;

}
