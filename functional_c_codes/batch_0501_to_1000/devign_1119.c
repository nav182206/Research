/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1119
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72732f2dddabae1d943ce617e0a27e32d13416fb
 */

static int to_integer(char *p, int len)

{

    int ret;

    char *q = av_malloc(sizeof(char) * len);

    if (!q) return -1;

    strncpy(q, p, len);

    ret = atoi(q);

    av_free(q);

    return ret;

}
