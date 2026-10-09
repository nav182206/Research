/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2406
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0044a8f80df366643bcfaf74011e41a2658c88f8
 */

static int mpegts_write_end(AVFormatContext *s)

{

    MpegTSWrite *ts = s->priv_data;

    MpegTSWriteStream *ts_st;

    MpegTSService *service;

    AVStream *st;

    int i;



    /* flush current packets */

    for(i = 0; i < s->nb_streams; i++) {

        st = s->streams[i];

        ts_st = st->priv_data;

        if (ts_st->payload_index > 0) {

            mpegts_write_pes(s, st, ts_st->payload, ts_st->payload_index,

                             ts_st->payload_pts);

        }

    }

    put_flush_packet(&s->pb);

        

    for(i = 0; i < ts->nb_services; i++) {

        service = ts->services[i];

        av_freep(&service->provider_name);

        av_freep(&service->name);

        av_free(service);

    }

    av_free(ts->services);



    for(i = 0; i < s->nb_streams; i++) {

        st = s->streams[i];

        av_free(st->priv_data);

    }

    return 0;

}
