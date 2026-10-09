/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7487
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12987f89007ee82b9d3a6090085dfaef8461ab8b
 */

static int gxf_seek(AVFormatContext *s, int stream_index, int64_t timestamp, int flags) {

    int res = 0;

    uint64_t pos;

    uint64_t maxlen = 100 * 1024 * 1024;

    AVStream *st = s->streams[0];

    int64_t start_time = s->streams[stream_index]->start_time;

    int64_t found;

    int idx;

    if (timestamp < start_time) timestamp = start_time;

    idx = av_index_search_timestamp(st, timestamp - start_time,

                                    AVSEEK_FLAG_ANY | AVSEEK_FLAG_BACKWARD);

    if (idx < 0)

        return -1;

    pos = st->index_entries[idx].pos;

    if (idx < st->nb_index_entries - 2)

        maxlen = st->index_entries[idx + 2].pos - pos;

    maxlen = FFMAX(maxlen, 200 * 1024);

    res = avio_seek(s->pb, pos, SEEK_SET);

    if (res < 0)

        return res;

    found = gxf_resync_media(s, maxlen, -1, timestamp);

    if (FFABS(found - timestamp) > 4)

        return -1;

    return 0;

}
