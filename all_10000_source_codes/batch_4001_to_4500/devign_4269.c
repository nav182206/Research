/* 
 * Benchmark Sample ID : devign_4269
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=87e8788680e16c51f6048af26f3f7830c35207a5
 */

static int dxa_probe(AVProbeData *p)

{

    /* check file header */

    if (p->buf_size <= 4)

        return 0;

    if (p->buf[0] == 'D' && p->buf[1] == 'E' &&

        p->buf[2] == 'X' && p->buf[3] == 'A')

        return AVPROBE_SCORE_MAX;

    else

        return 0;

}
