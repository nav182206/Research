/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9301
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0b42631641d998e509cde6fa344edc6ab5cb4ac8
 */

static int get_qcc(Jpeg2000DecoderContext *s, int n, Jpeg2000QuantStyle *q,

                   uint8_t *properties)

{

    int compno;



    if (s->buf_end - s->buf < 1)

        return AVERROR(EINVAL);



    compno              = bytestream_get_byte(&s->buf);

    properties[compno] |= HAD_QCC;

    return get_qcx(s, n - 1, q + compno);

}
