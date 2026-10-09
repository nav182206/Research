/* 
 * Benchmark Sample ID : devign_1819
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f8a9cf77040e1b2ed83206269ead11aa30afb98d
 */

static int lvf_probe(AVProbeData *p)

{

    if (AV_RL32(p->buf) == MKTAG('L', 'V', 'F', 'F'))

        return AVPROBE_SCORE_EXTENSION;

    return 0;

}
