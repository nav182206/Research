/* 
 * Benchmark Sample ID : devign_1071
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ba3517aa6f573d280d80866e776885be7f01de77
 */

void uninit_opts(void)

{

    int i;

    for (i = 0; i < AVMEDIA_TYPE_NB; i++)

        av_freep(&avcodec_opts[i]);

    av_freep(&avformat_opts->key);

    av_freep(&avformat_opts);

#if CONFIG_SWSCALE

    av_freep(&sws_opts);

#endif



}
