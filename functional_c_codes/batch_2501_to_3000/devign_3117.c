/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3117
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=75b9ed04b977bfd467816f7e60c6511ef89b8a2b
 */

int av_write_frame(AVFormatContext *s, AVPacket *pkt)

{

    int ret = compute_pkt_fields2(s, s->streams[pkt->stream_index], pkt);



    if(ret<0 && !(s->oformat->flags & AVFMT_NOTIMESTAMPS))

        return ret;



    ret= s->oformat->write_packet(s, pkt);

    if(!ret)

        ret= url_ferror(s->pb);

    return ret;

}
