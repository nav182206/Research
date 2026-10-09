/* 
 * Benchmark Sample ID : devign_4857
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=59c6178a54c414fd19e064f0077d00b82a1eb812
 */

static int flac_write_trailer(struct AVFormatContext *s)

{

    ByteIOContext *pb = s->pb;

    uint8_t *streaminfo = s->streams[0]->codec->extradata;

    int len = s->streams[0]->codec->extradata_size;

    int64_t file_size;



    if (streaminfo && len > 0 && !url_is_streamed(s->pb)) {

        file_size = url_ftell(pb);

        url_fseek(pb, 8, SEEK_SET);

        put_buffer(pb, streaminfo, len);

        url_fseek(pb, file_size, SEEK_SET);

        put_flush_packet(pb);

    }

    return 0;

}
