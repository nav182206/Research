/* 
 * Benchmark Sample ID : devign_2025
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0c1d62ab9d757d546fafca366d776524e7bb9893
 */

static int theora_packet(AVFormatContext *s, int idx)

{

    struct ogg *ogg = s->priv_data;

    struct ogg_stream *os = ogg->streams + idx;

    int duration;



    /* first packet handling

       here we parse the duration of each packet in the first page and compare

       the total duration to the page granule to find the encoder delay and

       set the first timestamp */



    if ((!os->lastpts || os->lastpts == AV_NOPTS_VALUE) && !(os->flags & OGG_FLAG_EOS)) {

        int seg;



        duration = 1;

        for (seg = os->segp; seg < os->nsegs; seg++) {

            if (os->segments[seg] < 255)

                duration ++;

        }



        os->lastpts = os->lastdts   = theora_gptopts(s, idx, os->granule, NULL) - duration;

        if(s->streams[idx]->start_time == AV_NOPTS_VALUE) {

            s->streams[idx]->start_time = os->lastpts;

            if (s->streams[idx]->duration)

                s->streams[idx]->duration -= s->streams[idx]->start_time;

        }

    }



    /* parse packet duration */

    if (os->psize > 0) {

        os->pduration = 1;

    }



    return 0;

}
