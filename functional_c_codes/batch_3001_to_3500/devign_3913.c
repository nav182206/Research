/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3913
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=229843aa359ae0c9519977d7fa952688db63f559
 */

static int ftp_close(URLContext *h)

{

    FTPContext *s = h->priv_data;



    av_dlog(h, "ftp protocol close\n");



    ftp_close_both_connections(s);

    av_freep(&s->user);

    av_freep(&s->password);

    av_freep(&s->hostname);

    av_freep(&s->path);

    av_freep(&s->features);



    return 0;

}
