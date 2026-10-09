/* 
 * Benchmark Sample ID : devign_7070
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=81c1657a593b1c0f8e46fca00ead1d30ee1cd418
 */

static int dvdsub_parse(AVCodecParserContext *s,

                        AVCodecContext *avctx,

                        const uint8_t **poutbuf, int *poutbuf_size,

                        const uint8_t *buf, int buf_size)

{

    DVDSubParseContext *pc = s->priv_data;



    if (pc->packet_index == 0) {

        if (buf_size < 2)

            return buf_size;

        pc->packet_len = AV_RB16(buf);

        if (pc->packet_len == 0) /* HD-DVD subpicture packet */

            pc->packet_len = AV_RB32(buf+2);

        av_freep(&pc->packet);

        pc->packet = av_malloc(pc->packet_len);

    }

    if (pc->packet) {

        if (pc->packet_index + buf_size <= pc->packet_len) {

            memcpy(pc->packet + pc->packet_index, buf, buf_size);

            pc->packet_index += buf_size;

            if (pc->packet_index >= pc->packet_len) {

                *poutbuf = pc->packet;

                *poutbuf_size = pc->packet_len;

                pc->packet_index = 0;

                return buf_size;

            }

        } else {

            /* erroneous size */

            pc->packet_index = 0;

        }

    }

    *poutbuf = NULL;

    *poutbuf_size = 0;

    return buf_size;

}
