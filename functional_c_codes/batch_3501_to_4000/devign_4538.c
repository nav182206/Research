/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4538
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b0635e2fcf80717dd618ef75d3317d62ed85c300
 */

static void mov_text_new_line_cb(void *priv, int forced)

{

    MovTextContext *s = priv;

    av_strlcpy(s->ptr, "\n", FFMIN(s->end - s->ptr, 2));

    s->ptr++;

}
