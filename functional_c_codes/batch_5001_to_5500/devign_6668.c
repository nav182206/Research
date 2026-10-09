/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6668
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=92a0f338786b629c5661f5b552e32c6154c3389d
 */

static void ffm_seek1(AVFormatContext *s, int64_t pos1)

{

    FFMContext *ffm = s->priv_data;

    ByteIOContext *pb = s->pb;

    int64_t pos;



    pos = pos1 + ffm->write_index;

    if (pos >= ffm->file_size)

        pos -= (ffm->file_size - FFM_PACKET_SIZE);

#ifdef DEBUG_SEEK

    av_log(s, AV_LOG_DEBUG, "seek to %"PRIx64" -> %"PRIx64"\n", pos1, pos);

#endif

    url_fseek(pb, pos, SEEK_SET);

}
