/* 
 * Benchmark Sample ID : devign_7261
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14b6160099f0caf5dc9d62e637b007bc5d719a96
 */

static void qmp_input_type_bool(Visitor *v, bool *obj, const char *name,

                                Error **errp)

{

    QmpInputVisitor *qiv = to_qiv(v);

    QObject *qobj = qmp_input_get_object(qiv, name, true);



    if (!qobj || qobject_type(qobj) != QTYPE_QBOOL) {

        error_setg(errp, QERR_INVALID_PARAMETER_TYPE, name ? name : "null",

                   "boolean");

        return;

    }



    *obj = qbool_get_bool(qobject_to_qbool(qobj));

}
