/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3001
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bc851a2946c64eefb96145b70e2190ff7d5a4827
 */

static int ogg_restore(AVFormatContext *s, int discard)

{

    struct ogg *ogg = s->priv_data;

    AVIOContext *bc = s->pb;

    struct ogg_state *ost = ogg->state;

    int i;



    if (!ost)

        return 0;



    ogg->state = ost->next;



    if (!discard){

        for (i = 0; i < ogg->nstreams; i++)

            av_free (ogg->streams[i].buf);



        avio_seek (bc, ost->pos, SEEK_SET);

        ogg->curidx = ost->curidx;

        ogg->nstreams = ost->nstreams;

        memcpy(ogg->streams, ost->streams,

               ost->nstreams * sizeof(*ogg->streams));

    }



    av_free (ost);



    return 0;

}
