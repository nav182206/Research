/* 
 * Benchmark Sample ID : devign_9848
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eae63e3c156f784ee0612422f0c95131ea913c14
 */

static int get_qcc(Jpeg2000DecoderContext *s, int n, Jpeg2000QuantStyle *q,

                   uint8_t *properties)

{

    int compno;



    if (bytestream2_get_bytes_left(&s->g) < 1)

        return AVERROR_INVALIDDATA;



    compno              = bytestream2_get_byteu(&s->g);

    properties[compno] |= HAD_QCC;

    return get_qcx(s, n - 1, q + compno);

}
