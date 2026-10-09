/* 
 * Benchmark Sample ID : devign_605
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1677155df8ee2dbf6c99738b289e27c2237506bd
 */

static void compute_frame_duration(int *pnum, int *pden, AVStream *st, 

                                   AVCodecParserContext *pc, AVPacket *pkt)

{

    int frame_size;



    *pnum = 0;

    *pden = 0;

    switch(st->codec.codec_type) {

    case CODEC_TYPE_VIDEO:

        if(st->time_base.num*1000 > st->time_base.den){

            *pnum = st->time_base.num;

            *pden = st->time_base.den;

        }else if(st->codec.time_base.num*1000 > st->codec.time_base.den){

            *pnum = st->codec.time_base.num;

            *pden = st->codec.time_base.den;

            if (pc && pc->repeat_pict) {

                *pden *= 2;

                *pnum = (*pnum) * (2 + pc->repeat_pict);

            }

        }

        break;

    case CODEC_TYPE_AUDIO:

        frame_size = get_audio_frame_size(&st->codec, pkt->size);

        if (frame_size < 0)

            break;

        *pnum = frame_size;

        *pden = st->codec.sample_rate;

        break;

    default:

        break;

    }

}
