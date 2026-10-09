/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2563
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0393cf15dbe3b136647b81676a105815924eebcd
 */

void av_parser_close(AVCodecParserContext *s)

{

    if(s){

        if (s->parser->parser_close) {

            ff_lock_avcodec(NULL);

            s->parser->parser_close(s);

            ff_unlock_avcodec();

        }

        av_free(s->priv_data);

        av_free(s);

    }

}
