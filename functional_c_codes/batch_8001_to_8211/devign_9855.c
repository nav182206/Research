/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9855
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=928cfc7e4f42aa283bb1bd9a50f0b3caa5a0f7a5
 */

static void ffm_seek1(AVFormatContext *s, int64_t pos1)

{

    FFMContext *ffm = s->priv_data;

    AVIOContext *pb = s->pb;

    int64_t pos;



    pos = FFMIN(pos1, ffm->file_size - FFM_PACKET_SIZE);

    pos = FFMAX(pos, FFM_PACKET_SIZE);

    av_dlog(s, "seek to %"PRIx64" -> %"PRIx64"\n", pos1, pos);

    avio_seek(pb, pos, SEEK_SET);

}
