/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8659
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aeccb522ebb6fb0378bccd6393f1d0c1ca40fdd4
 */

static int concat_read_packet(AVFormatContext *avf, AVPacket *pkt)
{
    ConcatContext *cat = avf->priv_data;
    int ret;
    int64_t delta;
    while (1) {
        if ((ret = av_read_frame(cat->avf, pkt)) != AVERROR_EOF ||
            (ret = open_next_file(avf)) < 0)
            break;
    }
    delta = av_rescale_q(cat->cur_file->start_time - cat->avf->start_time,
                         AV_TIME_BASE_Q,
                         cat->avf->streams[pkt->stream_index]->time_base);
    if (pkt->pts != AV_NOPTS_VALUE)
        pkt->pts += delta;
    if (pkt->dts != AV_NOPTS_VALUE)
        pkt->dts += delta;
}
