/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9082
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0a467a9b594dd67aa96bad687d05f8845b009f18
 */

static unsigned tget_long(const uint8_t **p, int le)

{

    unsigned v = le ? AV_RL32(*p) : AV_RB32(*p);

    *p += 4;

    return v;

}
