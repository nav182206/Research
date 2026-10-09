/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7380
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a7ba3244131d96d9ab7a99ef30dc7276efd05cc7
 */

static int aac_parse_packet(AVFormatContext *ctx, PayloadContext *data,

                            AVStream *st, AVPacket *pkt, uint32_t *timestamp,

                            const uint8_t *buf, int len, uint16_t seq,

                            int flags)

{

    int ret;

    if (rtp_parse_mp4_au(data, buf))

        return -1;



    buf += data->au_headers_length_bytes + 2;

    len -= data->au_headers_length_bytes + 2;



    /* XXX: Fixme we only handle the case where rtp_parse_mp4_au define

                    one au_header */

    if ((ret = av_new_packet(pkt, data->au_headers[0].size)) < 0)

        return ret;

    memcpy(pkt->data, buf, data->au_headers[0].size);



    pkt->stream_index = st->index;

    return 0;

}
