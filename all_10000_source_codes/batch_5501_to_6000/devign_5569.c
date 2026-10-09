/* 
 * Benchmark Sample ID : devign_5569
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=089fac77a6bf9199a5ec161e9c27850f0a680541
 */

static int audio_read_packet(AVFormatContext *s1, AVPacket *pkt)

{

    AlsaData *s  = s1->priv_data;

    AVStream *st = s1->streams[0];

    int res;

    snd_htimestamp_t timestamp;

    snd_pcm_uframes_t ts_delay;



    if (av_new_packet(pkt, s->period_size) < 0) {

        return AVERROR(EIO);

    }



    while ((res = snd_pcm_readi(s->h, pkt->data, pkt->size / s->frame_size)) < 0) {

        if (res == -EAGAIN) {

            av_free_packet(pkt);



            return AVERROR(EAGAIN);

        }

        if (ff_alsa_xrun_recover(s1, res) < 0) {

            av_log(s1, AV_LOG_ERROR, "ALSA read error: %s\n",

                   snd_strerror(res));

            av_free_packet(pkt);



            return AVERROR(EIO);

        }

    }



    snd_pcm_htimestamp(s->h, &ts_delay, &timestamp);

    ts_delay += res;

    pkt->pts = timestamp.tv_sec * 1000000LL

               + (timestamp.tv_nsec * st->codec->sample_rate

                  - ts_delay * 1000000000LL + st->codec->sample_rate * 500LL)

               / (st->codec->sample_rate * 1000LL);



    pkt->size = res * s->frame_size;



    return 0;

}
