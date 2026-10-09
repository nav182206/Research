/* 
 * Benchmark Sample ID : devign_9110
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=87e8788680e16c51f6048af26f3f7830c35207a5
 */

static int nuv_probe(AVProbeData *p) {

    if (p->buf_size < 12)

        return 0;

    if (!memcmp(p->buf, "NuppelVideo", 12))

        return AVPROBE_SCORE_MAX;

    if (!memcmp(p->buf, "MythTVVideo", 12))

        return AVPROBE_SCORE_MAX;

    return 0;

}
