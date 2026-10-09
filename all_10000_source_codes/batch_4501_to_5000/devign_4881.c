/* 
 * Benchmark Sample ID : devign_4881
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ed1f8915daf6b84a940463dfe83c7b970f82383d
 */

static void report_config_error(const char *filename, int line_num, int log_level, int *errors, const char *fmt, ...)

{

    va_list vl;

    va_start(vl, fmt);

    av_log(NULL, log_level, "%s:%d: ", filename, line_num);

    av_vlog(NULL, log_level, fmt, vl);

    va_end(vl);



    (*errors)++;

}
