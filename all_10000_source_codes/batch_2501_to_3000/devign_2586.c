/* 
 * Benchmark Sample ID : devign_2586
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9b01a8ad5ecf88aa0a8e52c2b70816e03ef59162
 */

void avformat_close_input(AVFormatContext **ps)

{

    AVFormatContext *s = *ps;

    AVIOContext *pb = (s->iformat->flags & AVFMT_NOFILE) || (s->flags & AVFMT_FLAG_CUSTOM_IO) ?

                       NULL : s->pb;

    flush_packet_queue(s);

    if (s->iformat->read_close)

        s->iformat->read_close(s);

    avformat_free_context(s);

    *ps = NULL;

    if (pb)

        avio_close(pb);

}
