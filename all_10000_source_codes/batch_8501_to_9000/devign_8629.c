/* 
 * Benchmark Sample ID : devign_8629
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e54165aa392322bbeeb823fc33a17336e465b7b5
 */

static int tta_read_seek(AVFormatContext *s, int stream_index, int64_t timestamp, int flags)

{

    TTAContext *c = s->priv_data;

    AVStream *st = s->streams[stream_index];

    int index = av_index_search_timestamp(st, timestamp, flags);

    if (index < 0)

        return -1;



    c->currentframe = index;

    avio_seek(s->pb, st->index_entries[index].pos, SEEK_SET);



    return 0;

}
