/* 
 * Benchmark Sample ID : devign_4926
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a9fc37f6bc3f2ab90585cb16493da9f6dcfbfbcf
 */

static void qobject_input_type_null(Visitor *v, const char *name, Error **errp)

{

    QObjectInputVisitor *qiv = to_qiv(v);

    QObject *qobj = qobject_input_get_object(qiv, name, true, errp);



    if (!qobj) {

        return;

    }



    if (qobject_type(qobj) != QTYPE_QNULL) {

        error_setg(errp, QERR_INVALID_PARAMETER_TYPE, name ? name : "null",

                   "null");

    }

}
