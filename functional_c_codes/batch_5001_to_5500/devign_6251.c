/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6251
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4dfbc7a7559ccab666a8fd39de4224eb4b02c768
 */

static int msnwc_tcp_read_packet(AVFormatContext *ctx, AVPacket *pkt)

{

    AVIOContext *pb = ctx->pb;

    uint16_t keyframe;

    uint32_t size, timestamp;



    avio_skip(pb, 1); /* one byte has been read ahead */

    avio_skip(pb, 2);

    avio_skip(pb, 2);

    keyframe = avio_rl16(pb);

    size = avio_rl32(pb);

    avio_skip(pb, 4);

    avio_skip(pb, 4);

    timestamp = avio_rl32(pb);



    if(!size || av_get_packet(pb, pkt, size) != size)

        return -1;



    avio_skip(pb, 1); /* Read ahead one byte of struct size like read_header */



    pkt->pts = timestamp;

    pkt->dts = timestamp;

    pkt->stream_index = 0;



    /* Some aMsn generated videos (or was it Mercury Messenger?) don't set

     * this bit and rely on the codec to get keyframe information */

    if(keyframe&1)

        pkt->flags |= AV_PKT_FLAG_KEY;



    return HEADER_SIZE + size;

}
