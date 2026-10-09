/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5952
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9bada8971173345ceb37ed1a47b00a01a4dd48cf
 */

static QObject *parse_value(JSONParserContext *ctxt, va_list *ap)

{

    QObject *token;



    token = parser_context_peek_token(ctxt);

    if (token == NULL) {

        parse_error(ctxt, NULL, "premature EOI");

        return NULL;

    }



    switch (token_get_type(token)) {

    case JSON_LCURLY:

        return parse_object(ctxt, ap);

    case JSON_LSQUARE:

        return parse_array(ctxt, ap);

    case JSON_ESCAPE:

        return parse_escape(ctxt, ap);

    case JSON_INTEGER:

    case JSON_FLOAT:

    case JSON_STRING:

        return parse_literal(ctxt);

    case JSON_KEYWORD:

        return parse_keyword(ctxt);

    default:

        parse_error(ctxt, token, "expecting value");

        return NULL;

    }

}
