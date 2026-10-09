/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7343
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ed412d285078c167a3a5326bcb16b2169b488943
 */

static void set_sar(TiffContext *s, unsigned tag, unsigned num, unsigned den)

{

    int offset = tag == TIFF_YRES ? 2 : 0;

    s->res[offset++] = num;

    s->res[offset]   = den;

    if (s->res[0] && s->res[1] && s->res[2] && s->res[3])

        av_reduce(&s->avctx->sample_aspect_ratio.num, &s->avctx->sample_aspect_ratio.den,

                  s->res[2] * (uint64_t)s->res[1], s->res[0] * (uint64_t)s->res[3], INT32_MAX);

}
