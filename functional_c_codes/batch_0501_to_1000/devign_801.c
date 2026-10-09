/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_801
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c96c84a9ff4bc184cb1f6cc9771a550f3854ba59
 */

static void parse_error(JSONParserContext *ctxt, QObject *token, const char *msg, ...)

{

    fprintf(stderr, "parse error: %s\n", msg);

}
