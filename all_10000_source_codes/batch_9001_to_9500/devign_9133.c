/* 
 * Benchmark Sample ID : devign_9133
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=89cad9f3ec6b30d7550fb5704475fc9c3393a066
 */

static void process_event(JSONMessageParser *parser, QList *tokens)

{

    GAState *s = container_of(parser, GAState, parser);

    QObject *obj;

    QDict *qdict;

    Error *err = NULL;

    int ret;



    g_assert(s && parser);



    g_debug("process_event: called");

    obj = json_parser_parse_err(tokens, NULL, &err);

    if (err || !obj || qobject_type(obj) != QTYPE_QDICT) {

        qobject_decref(obj);

        qdict = qdict_new();

        if (!err) {

            g_warning("failed to parse event: unknown error");

            error_setg(&err, QERR_JSON_PARSING);

        } else {

            g_warning("failed to parse event: %s", error_get_pretty(err));

        }

        qdict_put_obj(qdict, "error", qmp_build_error_object(err));

        error_free(err);

    } else {

        qdict = qobject_to_qdict(obj);

    }



    g_assert(qdict);



    /* handle host->guest commands */

    if (qdict_haskey(qdict, "execute")) {

        process_command(s, qdict);

    } else {

        if (!qdict_haskey(qdict, "error")) {

            QDECREF(qdict);

            qdict = qdict_new();

            g_warning("unrecognized payload format");

            error_setg(&err, QERR_UNSUPPORTED);

            qdict_put_obj(qdict, "error", qmp_build_error_object(err));

            error_free(err);

        }

        ret = send_response(s, QOBJECT(qdict));

        if (ret < 0) {

            g_warning("error sending error response: %s", strerror(-ret));

        }

    }



    QDECREF(qdict);

}
