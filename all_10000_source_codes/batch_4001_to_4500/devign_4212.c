/* 
 * Benchmark Sample ID : devign_4212
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=09e68369a88d7de0f988972bf28eec1b80cc47f9
 */

static void qmp_input_type_null(Visitor *v, const char *name, Error **errp)

{

    QmpInputVisitor *qiv = to_qiv(v);

    QObject *qobj = qmp_input_get_object(qiv, name, true, errp);



    if (!qobj) {

        return;

    }



    if (qobject_type(qobj) != QTYPE_QNULL) {

        error_setg(errp, QERR_INVALID_PARAMETER_TYPE, name ? name : "null",

                   "null");

    }

}
