/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5006
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b0635e2fcf80717dd618ef75d3317d62ed85c300
 */

static void mov_text_text_cb(void *priv, const char *text, int len)

{

    MovTextContext *s = priv;

    av_strlcpy(s->ptr, text, FFMIN(s->end - s->ptr, len + 1));

    s->ptr += len;

}
