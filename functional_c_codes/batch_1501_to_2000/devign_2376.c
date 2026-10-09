/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2376
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=87e8788680e16c51f6048af26f3f7830c35207a5
 */

static int ea_probe(AVProbeData *p)

{

    if (p->buf_size < 4)

        return 0;



    if (AV_RL32(&p->buf[0]) != SCHl_TAG)

        return 0;



    return AVPROBE_SCORE_MAX;

}
