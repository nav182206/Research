/* 
 * Benchmark Sample ID : devign_6257
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=87e8788680e16c51f6048af26f3f7830c35207a5
 */

static int nut_probe(AVProbeData *p) {

    if (p->buf_size >= ID_LENGTH && !memcmp(p->buf, ID_STRING, ID_LENGTH)) return AVPROBE_SCORE_MAX;



    return 0;

}
