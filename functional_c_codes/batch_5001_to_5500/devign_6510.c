/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6510
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7effbee66cf457c62f795d9b9ed3a1110b364b89
 */

static int raw_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    int ret, size, bps;

    //    AVStream *st = s->streams[0];



    size= RAW_SAMPLES*s->streams[0]->codec->block_align;



    ret= av_get_packet(s->pb, pkt, size);




    pkt->stream_index = 0;

    if (ret < 0)

        return ret;



    bps= av_get_bits_per_sample(s->streams[0]->codec->codec_id);

    assert(bps); // if false there IS a bug elsewhere (NOT in this function)

    pkt->dts=

    pkt->pts= pkt->pos*8 / (bps * s->streams[0]->codec->channels);



    return ret;

}
