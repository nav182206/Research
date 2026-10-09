/* 
 * Benchmark Sample ID : devign_4145
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f73e3938ac70524826664855210446c3739c4a5e
 */

static int mp3_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    int ret;



    ret = av_get_packet(s->pb, pkt, MP3_PACKET_SIZE);



    pkt->stream_index = 0;

    if (ret <= 0) {

        return AVERROR(EIO);

    }



    if (ret > ID3v1_TAG_SIZE &&

        memcmp(&pkt->data[ret - ID3v1_TAG_SIZE], "TAG", 3) == 0)

        ret -= ID3v1_TAG_SIZE;



    /* note: we need to modify the packet size here to handle the last

       packet */

    pkt->size = ret;

    return ret;

}
