/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3896
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f3b028c7117e03267ea7f88d0d612e70f1afc06
 */

static inline void json_print_item_str(WriterContext *wctx,

                                       const char *key, const char *value,

                                       const char *indent)

{

    char *key_esc = json_escape_str(key);

    char *value_esc = json_escape_str(value);



    printf("%s\"%s\": \"%s\"", indent,

           key_esc   ? key_esc   : "",

           value_esc ? value_esc : "");

    av_free(key_esc);

    av_free(value_esc);

}
