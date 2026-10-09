/* 
 * Benchmark Sample ID : devign_1658
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=919c320f7226bf873a9148e1db8994745f9d425d
 */

static void ogg_write_pages(AVFormatContext *s, int flush)

{

    OGGContext *ogg = s->priv_data;

    OGGPageList *next, *p;



    if (!ogg->page_list)

        return;



    for (p = ogg->page_list; p; ) {

        OGGStreamContext *oggstream =

            s->streams[p->page.stream_index]->priv_data;

        if (oggstream->page_count < 2 && !flush)

            break;

        ogg_write_page(s, &p->page,

                       flush && oggstream->page_count == 1 ? 4 : 0); // eos

        next = p->next;

        av_freep(&p);

        p = next;

    }

    ogg->page_list = p;

}
