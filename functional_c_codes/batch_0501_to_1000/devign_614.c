/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_614
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9cb5c760d73e08bcd5d441d261abe67d472e98ee
 */

void show_pix_fmts(void)

{

    list_fmts(avcodec_pix_fmt_string, PIX_FMT_NB);

}
