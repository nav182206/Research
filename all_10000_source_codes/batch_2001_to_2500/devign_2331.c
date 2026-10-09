/* 
 * Benchmark Sample ID : devign_2331
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e5e422bcc3e6deee8c5c5bf8f5aeca2c051542f5
 */

static int mxf_set_audio_pts(MXFContext *mxf, AVCodecContext *codec, AVPacket *pkt)

{

    MXFTrack *track = mxf->fc->streams[pkt->stream_index]->priv_data;

    pkt->pts = track->sample_count;

    if (codec->channels <= 0 || av_get_bits_per_sample(codec->codec_id) <= 0)

        return AVERROR(EINVAL);

    track->sample_count += pkt->size / (codec->channels * av_get_bits_per_sample(codec->codec_id) / 8);

    return 0;

}
