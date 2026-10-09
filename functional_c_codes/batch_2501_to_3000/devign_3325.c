/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3325
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7709ce029a7bc101b9ac1ceee607cda10dcb89dc
 */

void ff_compute_frame_duration(int *pnum, int *pden, AVStream *st,

                               AVCodecParserContext *pc, AVPacket *pkt)

{

    int frame_size;



    *pnum = 0;

    *pden = 0;

    switch(st->codec->codec_type) {

    case AVMEDIA_TYPE_VIDEO:

        if (st->avg_frame_rate.num) {

            *pnum = st->avg_frame_rate.den;

            *pden = st->avg_frame_rate.num;

        } else if(st->time_base.num*1000LL > st->time_base.den) {

            *pnum = st->time_base.num;

            *pden = st->time_base.den;

        }else if(st->codec->time_base.num*1000LL > st->codec->time_base.den){

            *pnum = st->codec->time_base.num;

            *pden = st->codec->time_base.den;

            if (pc && pc->repeat_pict) {

                *pnum = (*pnum) * (1 + pc->repeat_pict);

            }

            //If this codec can be interlaced or progressive then we need a parser to compute duration of a packet

            //Thus if we have no parser in such case leave duration undefined.

            if(st->codec->ticks_per_frame>1 && !pc){

                *pnum = *pden = 0;

            }

        }

        break;

    case AVMEDIA_TYPE_AUDIO:

        frame_size = ff_get_audio_frame_size(st->codec, pkt->size, 0);

        if (frame_size <= 0 || st->codec->sample_rate <= 0)

            break;

        *pnum = frame_size;

        *pden = st->codec->sample_rate;

        break;

    default:

        break;

    }

}
