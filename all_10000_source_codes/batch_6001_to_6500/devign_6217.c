/* 
 * Benchmark Sample ID : devign_6217
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=46db10ed0e04872eb9b003129f8395005c935ca4
 */

const char *avcodec_get_pix_fmt_name(enum PixelFormat pix_fmt)

{

    if (pix_fmt < 0 || pix_fmt >= PIX_FMT_NB)

        return NULL;

    else

        return av_pix_fmt_descriptors[pix_fmt].name;

}
