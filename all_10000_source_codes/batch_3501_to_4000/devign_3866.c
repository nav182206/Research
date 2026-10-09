/* 
 * Benchmark Sample ID : devign_3866
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7b5ff7d57355dc608f0fd86e3ab32a2fda65e752
 */

static void vp7_decode_mb_row_no_filter(AVCodecContext *avctx, void *tdata,

                                        int jobnr, int threadnr)

{

    decode_mb_row_no_filter(avctx, tdata, jobnr, threadnr, 1);

}
