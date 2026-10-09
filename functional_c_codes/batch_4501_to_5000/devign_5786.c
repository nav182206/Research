/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5786
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b57083529650be5417056453fae8b2bf2dface59
 */

static int ape_probe(AVProbeData * p)

{

    if (p->buf[0] == 'M' && p->buf[1] == 'A' && p->buf[2] == 'C' && p->buf[3] == ' ')

        return AVPROBE_SCORE_MAX;



    return 0;

}
