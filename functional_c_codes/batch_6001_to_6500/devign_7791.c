/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7791
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=269fc8e04906ffd965aa19425ca90980b23c6508
 */

static int write_header(AVFormatContext *s)

{

    AVCodecContext *codec = s->streams[0]->codec;



    if (s->nb_streams > 1) {

        av_log(s, AV_LOG_ERROR, "only one stream is supported\n");

        return AVERROR(EINVAL);

    }

    if (codec->codec_id != AV_CODEC_ID_WAVPACK) {

        av_log(s, AV_LOG_ERROR, "unsupported codec\n");

        return AVERROR(EINVAL);

    }

    if (codec->extradata_size > 0) {

        avpriv_report_missing_feature(s, "remuxing from matroska container");

        return AVERROR_PATCHWELCOME;

    }

    avpriv_set_pts_info(s->streams[0], 64, 1, codec->sample_rate);



    return 0;

}
