/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1055
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9bada8971173345ceb37ed1a47b00a01a4dd48cf
 */

static void parser_context_free(JSONParserContext *ctxt)

{

    if (ctxt) {

        while (!g_queue_is_empty(ctxt->buf)) {

            parser_context_pop_token(ctxt);

        }

        qobject_decref(ctxt->current);

        g_queue_free(ctxt->buf);

        g_free(ctxt);

    }

}
