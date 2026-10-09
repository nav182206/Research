/* 
 * Benchmark Sample ID : devign_8714
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7a961a46ba28e49f88ff0e81b96395c96b424634
 */

void register_avcodec(AVCodec *codec)

{

    AVCodec **p;


    p = &first_avcodec;

    while (*p != NULL) p = &(*p)->next;

    *p = codec;

    codec->next = NULL;

}
