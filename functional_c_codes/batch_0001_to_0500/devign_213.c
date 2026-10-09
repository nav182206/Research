/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_213
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2779d33ed99898675e0b3884fabe1ce6839f36d1
 */

static int adts_aac_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    int ret, fsize;



    ret = av_get_packet(s->pb, pkt, ADTS_HEADER_SIZE);

    if (ret < 0)

        return ret;

    if (ret < ADTS_HEADER_SIZE) {

        av_packet_unref(pkt);

        return AVERROR(EIO);

    }



    if ((AV_RB16(pkt->data) >> 4) != 0xfff) {

        av_packet_unref(pkt);

        return AVERROR_INVALIDDATA;

    }



    fsize = (AV_RB32(pkt->data + 3) >> 13) & 0x1FFF;

    if (fsize < ADTS_HEADER_SIZE) {

        av_packet_unref(pkt);

        return AVERROR_INVALIDDATA;

    }



    return av_append_packet(s->pb, pkt, fsize - ADTS_HEADER_SIZE);

}
