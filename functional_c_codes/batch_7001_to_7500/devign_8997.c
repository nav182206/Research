/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8997
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ddfa3751c092feaf1e080f66587024689dfe603c
 */

static int get_qcc(J2kDecoderContext *s, int n, J2kQuantStyle *q, uint8_t *properties)

{

    int compno;



    if (s->buf_end - s->buf < 1)

        return AVERROR(EINVAL);



    compno = bytestream_get_byte(&s->buf);

    properties[compno] |= HAD_QCC;

    return get_qcx(s, n-1, q+compno);

}
