/* 
 * Benchmark Sample ID : devign_8152
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=87e8788680e16c51f6048af26f3f7830c35207a5
 */

static int smacker_probe(AVProbeData *p)

{

    if (p->buf_size < 4)

        return 0;

    if(p->buf[0] == 'S' && p->buf[1] == 'M' && p->buf[2] == 'K'

        && (p->buf[3] == '2' || p->buf[3] == '4'))

        return AVPROBE_SCORE_MAX;

    else

        return 0;

}
