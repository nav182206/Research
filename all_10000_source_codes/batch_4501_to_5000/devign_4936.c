/* 
 * Benchmark Sample ID : devign_4936
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8e91d9652ea5048d9014e7636e12c6ed4732d7b7
 */

static int opt_vstats(void *optctx, const char *opt, const char *arg)
{
    char filename[40];
    time_t today2 = time(NULL);
    struct tm *today = localtime(&today2);
    snprintf(filename, sizeof(filename), "vstats_%02d%02d%02d.log", today->tm_hour, today->tm_min,
             today->tm_sec);
    return opt_vstats_file(NULL, opt, filename);
}
