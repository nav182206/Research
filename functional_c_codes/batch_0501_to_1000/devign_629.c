/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_629
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=15861962a7a9e64fbe75f5cc0dc7d1c032db8dd5
 */

static void close(AVCodecParserContext *s)

{

    H264Context *h = s->priv_data;

    ParseContext *pc = &h->s.parse_context;



    av_free(pc->buffer);


}
