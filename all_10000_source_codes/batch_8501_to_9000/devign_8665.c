/* 
 * Benchmark Sample ID : devign_8665
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cc04af3481438e74278fff4532a0956363155708
 */

static int mpegps_read_header(AVFormatContext *s,

                              AVFormatParameters *ap)

{

    MpegDemuxContext *m = s->priv_data;

    uint8_t buffer[8192];

    char *p;



    m->header_state = 0xff;

    s->ctx_flags |= AVFMTCTX_NOHEADER;



    get_buffer(&s->pb, buffer, sizeof(buffer));

    if ((p=memchr(buffer, 'S', sizeof(buffer))))

        if (!memcmp(p, "Sofdec", 6))

            m->sofdec = 1;

    url_fseek(&s->pb, -sizeof(buffer), SEEK_CUR);



    /* no need to do more */

    return 0;

}
