/* 
 * Benchmark Sample ID : devign_9554
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1b3b018aa4e43d7bf87df5cdf28c69a9ad5a6cbc
 */

static char *getstr8(const uint8_t **pp, const uint8_t *p_end)

{

    int len;

    const uint8_t *p;

    char *str;



    p   = *pp;

    len = get8(&p, p_end);

    if (len < 0)

        return NULL;

    if ((p + len) > p_end)

        return NULL;

    str = av_malloc(len + 1);

    if (!str)

        return NULL;

    memcpy(str, p, len);

    str[len] = '\0';

    p  += len;

    *pp = p;

    return str;

}
