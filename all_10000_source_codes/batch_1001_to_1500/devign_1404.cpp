/* 
 * Benchmark Sample ID : devign_1404
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0491a2a07a44f6e5e6f34081835e402c07025fd2
 */

static void default_show_tags(WriterContext *wctx, AVDictionary *dict)

{

    AVDictionaryEntry *tag = NULL;

    while ((tag = av_dict_get(dict, "", tag, AV_DICT_IGNORE_SUFFIX))) {

        printf("TAG:");

        writer_print_string(wctx, tag->key, tag->value);

    }

}
