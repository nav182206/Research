/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5273
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca6c3f2c53be70aa3c38e8f1292809db89ea1ba6
 */

static inline void copy_backptr(LZOContext *c, int back, int cnt)

{

    register const uint8_t *src = &c->out[-back];

    register uint8_t *dst       = c->out;

    if (src < c->out_start || src > dst) {

        c->error |= AV_LZO_INVALID_BACKPTR;

        return;

    }

    if (cnt > c->out_end - dst) {

        cnt       = FFMAX(c->out_end - dst, 0);

        c->error |= AV_LZO_OUTPUT_FULL;

    }

    av_memcpy_backptr(dst, back, cnt);

    c->out = dst + cnt;

}
