/* 
 * Benchmark Sample ID : devign_5426
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=12a419dacb479d663f04e316f9997568ef326965
 */

static int v210_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    int packet_size, ret, width, height;

    AVStream *st = s->streams[0];



    width = st->codec->width;

    height = st->codec->height;



    packet_size = GET_PACKET_SIZE(width, height);

    if (packet_size < 0)

        return -1;



    ret = av_get_packet(s->pb, pkt, packet_size);

    pkt->pts = pkt->dts = pkt->pos / packet_size;



    pkt->stream_index = 0;

    if (ret < 0)

        return ret;

    return 0;

}
