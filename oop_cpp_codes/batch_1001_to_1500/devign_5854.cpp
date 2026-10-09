/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5854
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ac1bf88c00dbe7eb2191e2d5325fb104b9d8341
 */

AVFormatContext *avformat_alloc_context(void)

{

    AVFormatContext *ic;

    ic = av_malloc(sizeof(AVFormatContext));

    if (!ic) return ic;

    avformat_get_context_defaults(ic);

    ic->av_class = &av_format_context_class;

    return ic;

}
