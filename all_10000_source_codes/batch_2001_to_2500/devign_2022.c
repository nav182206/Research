/* 
 * Benchmark Sample ID : devign_2022
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dee7943819042f310d7995671d3e39f4dd31d770
 */

static int qdraw_probe(AVProbeData *p)

{

    const uint8_t *b = p->buf;



    if (!b[10] && AV_RB32(b+11) == 0x1102ff0c && !b[15] ||

        p->buf_size >= 528 && !b[522] && AV_RB32(b+523) == 0x1102ff0c && !b[527])

        return AVPROBE_SCORE_EXTENSION + 1;

    return 0;

}
