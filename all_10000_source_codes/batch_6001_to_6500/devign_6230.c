/* 
 * Benchmark Sample ID : devign_6230
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=74942685cb457c01937686892878403a409baf27
 */

static int url_connect(struct variant *var, AVDictionary *opts)

{

    AVDictionary *tmp = NULL;

    int ret;



    av_dict_copy(&tmp, opts, 0);



    av_opt_set_dict(var->input, &tmp);



    if ((ret = ffurl_connect(var->input, NULL)) < 0) {

        ffurl_close(var->input);

        var->input = NULL;

    }



    av_dict_free(&tmp);

    return ret;

}
