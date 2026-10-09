/* 
 * Benchmark Sample ID : devign_1372
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a62242678ff96eade59960d1bbf65e4f3f03344f
 */

static int opt_sameq(void *optctx, const char *opt, const char *arg)

{

    av_log(NULL, AV_LOG_WARNING, "Ignoring option '%s'\n", opt);

    return 0;

}
