/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4796
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=636ced8e1dc8248a1353b416240b93d70ad03edb
 */

double parse_number_or_die(const char *context, const char *numstr, int type,

                           double min, double max)

{

    char *tail;

    const char *error;

    double d = av_strtod(numstr, &tail);

    if (*tail)

        error = "Expected number for %s but found: %s\n";

    else if (d < min || d > max)

        error = "The value for %s was %s which is not within %f - %f\n";

    else if (type == OPT_INT64 && (int64_t)d != d)

        error = "Expected int64 for %s but found %s\n";

    else if (type == OPT_INT && (int)d != d)

        error = "Expected int for %s but found %s\n";

    else

        return d;

    av_log(NULL, AV_LOG_FATAL, error, context, numstr, min, max);

    exit(1);

    return 0;

}
