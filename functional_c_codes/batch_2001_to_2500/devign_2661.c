/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2661
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c5fd57f483d2ad8e34551b78509f1e14136f73c0
 */

static int vp8_packet(AVFormatContext *s, int idx)

{

    struct ogg *ogg = s->priv_data;

    struct ogg_stream *os = ogg->streams + idx;

    uint8_t *p = os->buf + os->pstart;



    if ((!os->lastpts || os->lastpts == AV_NOPTS_VALUE) &&

        !(os->flags & OGG_FLAG_EOS)) {

        int seg;

        int duration;

        uint8_t *last_pkt = p;

        uint8_t *next_pkt;



        seg = os->segp;

        duration = (last_pkt[0] >> 4) & 1;

        next_pkt = last_pkt += os->psize;

        for (; seg < os->nsegs; seg++) {

            if (os->segments[seg] < 255) {

                duration += (last_pkt[0] >> 4) & 1;

                last_pkt  = next_pkt + os->segments[seg];

            }

            next_pkt += os->segments[seg];

        }

        os->lastpts =

        os->lastdts = vp8_gptopts(s, idx, os->granule, NULL) - duration;

        if(s->streams[idx]->start_time == AV_NOPTS_VALUE) {

            s->streams[idx]->start_time = os->lastpts;

            if (s->streams[idx]->duration)

                s->streams[idx]->duration -= s->streams[idx]->start_time;

        }

    }



    if (os->psize > 0)

        os->pduration = (p[0] >> 4) & 1;



    return 0;

}
