/* 
 * Benchmark Sample ID : devign_1412
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=88ad79415c3821e5c4f3cb4d5b289d772fcac621
 */

static int mpc8_read_seek(AVFormatContext *s, int stream_index, int64_t timestamp, int flags)

{

    AVStream *st = s->streams[stream_index];

    MPCContext *c = s->priv_data;

    int index = av_index_search_timestamp(st, timestamp, flags);



    if(index < 0) return -1;

    avio_seek(s->pb, st->index_entries[index].pos, SEEK_SET);

    c->frame = st->index_entries[index].timestamp;

    return 0;

}
