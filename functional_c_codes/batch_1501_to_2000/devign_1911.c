/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1911
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5edea431d0616737e5a5f58cefc07ba5b2e0875f
 */

int av_write_frame(AVFormatContext *s, AVPacket *pkt)

{

    int ret;



    compute_pkt_fields2(s->streams[pkt->stream_index], pkt);

    

    truncate_ts(s->streams[pkt->stream_index], pkt);



    ret= s->oformat->write_packet(s, pkt);

    if(!ret)

        ret= url_ferror(&s->pb);

    return ret;

}
