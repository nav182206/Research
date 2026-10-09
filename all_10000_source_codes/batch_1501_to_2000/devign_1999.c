/* 
 * Benchmark Sample ID : devign_1999
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e5c32d6da7836c7c9bb8393cb4de7e0997a4363b
 */

static int opt_debug(void *optctx, const char *opt, const char *arg)

{

    av_log_set_level(99);

    debug = parse_number_or_die(opt, arg, OPT_INT64, 0, INT_MAX);

    return 0;

}
