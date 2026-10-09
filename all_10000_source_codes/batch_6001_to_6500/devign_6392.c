/* 
 * Benchmark Sample ID : devign_6392
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bdab2421a540efc0593c87e6d247427a0a6e16bc
 */

static int dfa_probe(AVProbeData *p)
{
    if (p->buf_size < 4 || AV_RL32(p->buf) != MKTAG('D', 'F', 'I', 'A'))
        return 0;
    return AVPROBE_SCORE_MAX;
}
