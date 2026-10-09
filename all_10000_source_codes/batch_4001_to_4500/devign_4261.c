/* 
 * Benchmark Sample ID : devign_4261
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f3b028c7117e03267ea7f88d0d612e70f1afc06
 */

static void json_print_int(WriterContext *wctx, const char *key, int value)

{

    char *key_esc = json_escape_str(key);



    if (wctx->nb_item) printf(",\n");

    printf(INDENT "\"%s\": %d", key_esc ? key_esc : "", value);

    av_free(key_esc);

}
