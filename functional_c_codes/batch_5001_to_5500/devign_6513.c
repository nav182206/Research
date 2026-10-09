/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6513
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8bb376cf6b4ab8645daedb8becaa7163656436a4
 */

static int cmp_func_names(const char *a, const char *b)

{

    int ascii_diff, digit_diff;



    for (; !(ascii_diff = *a - *b) && *a; a++, b++);

    for (; av_isdigit(*a) && av_isdigit(*b); a++, b++);



    return (digit_diff = av_isdigit(*a) - av_isdigit(*b)) ? digit_diff : ascii_diff;

}
