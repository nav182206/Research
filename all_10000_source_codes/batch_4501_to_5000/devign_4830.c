/* 
 * Benchmark Sample ID : devign_4830
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1a3598aae768465a8efc8475b6df5a8261bc62fc
 */

static int get_cod(Jpeg2000DecoderContext *s, Jpeg2000CodingStyle *c,

                   uint8_t *properties)

{

    Jpeg2000CodingStyle tmp;

    int compno;



    if (s->buf_end - s->buf < 5)

        return AVERROR_INVALIDDATA;



    tmp.log2_prec_width  =

    tmp.log2_prec_height = 15;



    tmp.csty = bytestream_get_byte(&s->buf);



    // get progression order

    tmp.prog_order = bytestream_get_byte(&s->buf);



    tmp.nlayers = bytestream_get_be16(&s->buf);

    tmp.mct     = bytestream_get_byte(&s->buf); // multiple component transformation



    get_cox(s, &tmp);

    for (compno = 0; compno < s->ncomponents; compno++)

        if (!(properties[compno] & HAD_COC))

            memcpy(c + compno, &tmp, sizeof(tmp));

    return 0;

}
