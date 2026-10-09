/* 
 * Benchmark Sample ID : devign_9319
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1ec83d9a9e472f485897ac92bad9631d551a8c5b
 */

static unsigned tget_long(const uint8_t **p, int le)

{

    unsigned v = le ? AV_RL32(*p) : AV_RB32(*p);

    *p += 4;

    return v;

}
