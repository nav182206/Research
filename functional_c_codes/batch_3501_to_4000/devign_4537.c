/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4537
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ec3b22326dc07fb8300a577bd6b17c19a0f1bcf7
 */

int add_av_stream(FFStream *feed,

                  AVStream *st)

{

    AVStream *fst;

    AVCodecContext *av, *av1;

    int i;



    av = &st->codec;

    for(i=0;i<feed->nb_streams;i++) {

        st = feed->streams[i];

        av1 = &st->codec;

        if (av1->codec_id == av->codec_id &&

            av1->codec_type == av->codec_type &&

            av1->bit_rate == av->bit_rate) {



            switch(av->codec_type) {

            case CODEC_TYPE_AUDIO:

                if (av1->channels == av->channels &&

                    av1->sample_rate == av->sample_rate)

                    goto found;

                break;

            case CODEC_TYPE_VIDEO:

                if (av1->width == av->width &&

                    av1->height == av->height &&

                    av1->frame_rate == av->frame_rate &&

                    av1->gop_size == av->gop_size)

                    goto found;

                break;

            default:

                abort();

            }

        }

    }

    

    fst = av_mallocz(sizeof(AVStream));

    if (!fst)

        return -1;

    fst->priv_data = av_mallocz(sizeof(FeedData));

    memcpy(&fst->codec, av, sizeof(AVCodecContext));

    feed->streams[feed->nb_streams++] = fst;

    return feed->nb_streams - 1;

 found:

    return i;

}
