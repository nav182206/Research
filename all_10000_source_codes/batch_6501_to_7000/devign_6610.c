/* 
 * Benchmark Sample ID : devign_6610
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9bada8971173345ceb37ed1a47b00a01a4dd48cf
 */

static QObject *parser_context_peek_token(JSONParserContext *ctxt)

{

    assert(!g_queue_is_empty(ctxt->buf));

    return g_queue_peek_head(ctxt->buf);

}
