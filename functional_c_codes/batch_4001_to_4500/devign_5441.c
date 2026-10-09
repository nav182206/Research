/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5441
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=65c0f1e9558c7c762cdb333406243fff1d687117
 */

QObject *json_parser_parse_err(QList *tokens, va_list *ap, Error **errp)

{

    JSONParserContext ctxt = {};

    QList *working;

    QObject *result;



    if (!tokens) {

        return NULL;

    }

    working = qlist_copy(tokens);

    result = parse_value(&ctxt, &working, ap);



    QDECREF(working);



    error_propagate(errp, ctxt.err);



    return result;

}
