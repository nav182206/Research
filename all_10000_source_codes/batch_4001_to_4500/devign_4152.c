/* 
 * Benchmark Sample ID : devign_4152
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f907615f0813e8499f06a7eebccf1c63fce87c8e
 */

static int init(AVCodecParserContext *s)

{

    H264Context *h = s->priv_data;

    h->thread_context[0] = h;


    return 0;

}
