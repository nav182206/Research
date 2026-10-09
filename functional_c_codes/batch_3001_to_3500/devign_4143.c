/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4143
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=64476d7ee86e01f43312dc5dff850d641d2b6c9a
 */

static int read_seek(AVFormatContext *s, int stream_index, int64_t timestamp, int flags)

{

    AVStream *st = s->streams[stream_index];

    avio_seek(s->pb, FFMAX(timestamp, 0) * st->codec->width * st->codec->height * 4, SEEK_SET);

    return 0;

}
