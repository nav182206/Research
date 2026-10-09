/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9419
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1b3b018aa4e43d7bf87df5cdf28c69a9ad5a6cbc
 */

static inline int get16(const uint8_t **pp, const uint8_t *p_end)

{

    const uint8_t *p;

    int c;



    p = *pp;

    if ((p + 1) >= p_end)

        return AVERROR_INVALIDDATA;

    c   = AV_RB16(p);

    p  += 2;

    *pp = p;

    return c;

}
