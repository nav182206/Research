/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9176
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f495fbe76a2665cdea092999ca2dbb603d13280c
 */

int avio_check(const char *url, int flags)

{

    URLContext *h;

    int ret = ffurl_alloc(&h, url, flags, NULL);

    if (ret)

        return ret;



    if (h->prot->url_check) {

        ret = h->prot->url_check(h, flags);

    } else {

        ret = ffurl_connect(h, NULL);

        if (ret >= 0)

            ret = flags;

    }



    ffurl_close(h);

    return ret;

}
