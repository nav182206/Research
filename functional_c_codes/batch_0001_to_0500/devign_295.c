/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_295
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4733a12dd17a91d606e0079ff9bb48b9f419cbef
 */

int ff_wms_parse_sdp_a_line(AVFormatContext *s, const char *p)

{

    int ret = 0;

    if (av_strstart(p, "pgmpu:data:application/vnd.ms.wms-hdr.asfv1;base64,", &p)) {

        AVIOContext pb;

        RTSPState *rt = s->priv_data;

        AVDictionary *opts = NULL;

        int len = strlen(p) * 6 / 8;

        char *buf = av_mallocz(len);

        av_base64_decode(buf, p, len);



        if (rtp_asf_fix_header(buf, len) < 0)

            av_log(s, AV_LOG_ERROR,

                   "Failed to fix invalid RTSP-MS/ASF min_pktsize\n");

        init_packetizer(&pb, buf, len);

        if (rt->asf_ctx) {

            avformat_close_input(&rt->asf_ctx);

        }

        if (!(rt->asf_ctx = avformat_alloc_context()))

            return AVERROR(ENOMEM);

        rt->asf_ctx->pb      = &pb;

        av_dict_set(&opts, "no_resync_search", "1", 0);

        ret = avformat_open_input(&rt->asf_ctx, "", &ff_asf_demuxer, &opts);

        av_dict_free(&opts);

        if (ret < 0)

            return ret;

        av_dict_copy(&s->metadata, rt->asf_ctx->metadata, 0);

        rt->asf_pb_pos = avio_tell(&pb);

        av_free(buf);

        rt->asf_ctx->pb = NULL;

    }

    return ret;

}
