/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_65
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f73f76fd202b310e8e1d0215b2e0cf038cd18c4a
 */

SwsContext *sws_alloc_context(void)

{

    SwsContext *c = av_mallocz(sizeof(SwsContext));



    c->av_class = &sws_context_class;

    av_opt_set_defaults(c);



    return c;

}
