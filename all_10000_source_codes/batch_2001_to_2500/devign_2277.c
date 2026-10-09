/* 
 * Benchmark Sample ID : devign_2277
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=636ced8e1dc8248a1353b416240b93d70ad03edb
 */

int64_t parse_time_or_die(const char *context, const char *timestr,

                          int is_duration)

{

    int64_t us;

    if (av_parse_time(&us, timestr, is_duration) < 0) {

        av_log(NULL, AV_LOG_FATAL, "Invalid %s specification for %s: %s\n",

               is_duration ? "duration" : "date", context, timestr);

        exit(1);

    }

    return us;

}
