/* 
 * Benchmark Sample ID : devign_758
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=55fa898969d10e2d47bba0613175bf57a86c5a41
 */

static int get_qcd(Jpeg2000DecoderContext *s, int n, Jpeg2000QuantStyle *q,
                   uint8_t *properties)
{
    Jpeg2000QuantStyle tmp;
    int compno, ret;
    if ((ret = get_qcx(s, n, &tmp)) < 0)
        return ret;
    for (compno = 0; compno < s->ncomponents; compno++)
        if (!(properties[compno] & HAD_QCC))
            memcpy(q + compno, &tmp, sizeof(tmp));
    return 0;
}
