/* 
 * Benchmark Sample ID : devign_7612
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9257692ac15eff7b07540c1f61cebde0d8823fbd
 */

AVFormatContext *avformat_alloc_context(void)

{

    AVFormatContext *ic;

    ic = av_malloc(sizeof(AVFormatContext));

    if (!ic) return ic;

    avformat_get_context_defaults(ic);




    ic->internal = av_mallocz(sizeof(*ic->internal));

    if (!ic->internal) {

        avformat_free_context(ic);

        return NULL;

    }



    return ic;

}
