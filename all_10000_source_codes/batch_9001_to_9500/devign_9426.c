/* 
 * Benchmark Sample ID : devign_9426
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=229843aa359ae0c9519977d7fa952688db63f559
 */

static int write_skip_frames(AVFormatContext *s, int stream_index, int64_t dts)

{

    AVIStream *avist    = s->streams[stream_index]->priv_data;

    AVCodecContext *enc = s->streams[stream_index]->codec;



    av_dlog(s, "dts:%s packet_count:%d stream_index:%d\n", av_ts2str(dts), avist->packet_count, stream_index);

    while (enc->block_align == 0 && dts != AV_NOPTS_VALUE &&

           dts > avist->packet_count && enc->codec_id != AV_CODEC_ID_XSUB && avist->packet_count) {

        AVPacket empty_packet;



        if (dts - avist->packet_count > 60000) {

            av_log(s, AV_LOG_ERROR, "Too large number of skipped frames %"PRId64" > 60000\n", dts - avist->packet_count);

            return AVERROR(EINVAL);

        }



        av_init_packet(&empty_packet);

        empty_packet.size         = 0;

        empty_packet.data         = NULL;

        empty_packet.stream_index = stream_index;

        avi_write_packet(s, &empty_packet);

        av_dlog(s, "dup dts:%s packet_count:%d\n", av_ts2str(dts), avist->packet_count);

    }



    return 0;

}
