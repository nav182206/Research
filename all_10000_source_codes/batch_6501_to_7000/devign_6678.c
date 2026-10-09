/* 
 * Benchmark Sample ID : devign_6678
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=229843aa359ae0c9519977d7fa952688db63f559
 */

static int64_t get_dts(AVFormatContext *s, int64_t pos)

{

    AVIOContext *pb = s->pb;

    int64_t dts;



    ffm_seek1(s, pos);

    avio_skip(pb, 4);

    dts = avio_rb64(pb);

    av_dlog(s, "dts=%0.6f\n", dts / 1000000.0);

    return dts;

}
