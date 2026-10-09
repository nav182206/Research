/* 
 * Benchmark Sample ID : devign_9357
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4977e467a50a690a46af5988d568eaab2e5933c7
 */

static int raw_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    TAKDemuxContext *tc = s->priv_data;

    int ret;



    if (tc->mlast_frame) {

        AVIOContext *pb = s->pb;

        int64_t size, left;



        left = tc->data_end - avio_tell(s->pb);

        size = FFMIN(left, 1024);

        if (size <= 0)

            return AVERROR_EOF;



        ret = av_get_packet(pb, pkt, size);

        if (ret < 0)

            return ret;



        pkt->stream_index = 0;

    } else {

        ret = ff_raw_read_partial_packet(s, pkt);

    }



    return ret;

}
