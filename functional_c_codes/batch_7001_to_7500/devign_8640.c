/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8640
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7effbee66cf457c62f795d9b9ed3a1110b364b89
 */

static int rso_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    int bps = av_get_bits_per_sample(s->streams[0]->codec->codec_id);

    int ret = av_get_packet(s->pb, pkt, BLOCK_SIZE * bps >> 3);



    if (ret < 0)

        return ret;




    pkt->stream_index = 0;



    /* note: we need to modify the packet size here to handle the last packet */

    pkt->size = ret;



    return 0;

}
