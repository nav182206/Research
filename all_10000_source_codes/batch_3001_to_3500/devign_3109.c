/* 
 * Benchmark Sample ID : devign_3109
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0acf7e268b2f873379cd854b4d5aaba6f9c1f0b5
 */

int avfilter_init_str(AVFilterContext *filter, const char *args)

{

    return avfilter_init_filter(filter, args, NULL);

}
