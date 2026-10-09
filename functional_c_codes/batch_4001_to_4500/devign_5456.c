/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5456
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4eca1939ef0614d0959fffb93f93d44af6740e8c
 */

static int url_connect(struct playlist *pls, AVDictionary *opts, AVDictionary *opts2)

{

    AVDictionary *tmp = NULL;

    int ret;



    av_dict_copy(&tmp, opts, 0);

    av_dict_copy(&tmp, opts2, 0);



    av_opt_set_dict(pls->input, &tmp);



    if ((ret = ffurl_connect(pls->input, NULL)) < 0) {

        ffurl_close(pls->input);

        pls->input = NULL;

    }



    av_dict_free(&tmp);

    return ret;

}
