/* 
 * Benchmark Sample ID : devign_5396
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=87e8788680e16c51f6048af26f3f7830c35207a5
 */

static int roq_probe(AVProbeData *p)

{

    if (p->buf_size < 6)

        return 0;



    if ((AV_RL16(&p->buf[0]) != RoQ_MAGIC_NUMBER) ||

        (AV_RL32(&p->buf[2]) != 0xFFFFFFFF))

        return 0;



    return AVPROBE_SCORE_MAX;

}
