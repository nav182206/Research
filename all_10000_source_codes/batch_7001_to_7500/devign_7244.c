/* 
 * Benchmark Sample ID : devign_7244
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=09e68369a88d7de0f988972bf28eec1b80cc47f9
 */

static void qmp_input_type_uint64(Visitor *v, const char *name, uint64_t *obj,

                                  Error **errp)

{

    /* FIXME: qobject_to_qint mishandles values over INT64_MAX */

    QmpInputVisitor *qiv = to_qiv(v);

    QObject *qobj = qmp_input_get_object(qiv, name, true, errp);

    QInt *qint;



    if (!qobj) {

        return;

    }

    qint = qobject_to_qint(qobj);

    if (!qint) {

        error_setg(errp, QERR_INVALID_PARAMETER_TYPE, name ? name : "null",

                   "integer");

        return;

    }



    *obj = qint_get_int(qint);

}
