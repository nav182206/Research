/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3548
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fcf73f66a67f5e58c18216f8c8651e38cf4d90af
 */

static void qmp_input_type_int(Visitor *v, int64_t *obj, const char *name,

                               Error **errp)

{

    QmpInputVisitor *qiv = to_qiv(v);

    QObject *qobj = qmp_input_get_object(qiv, name, true);



    if (!qobj || qobject_type(qobj) != QTYPE_QINT) {

        error_setg(errp, QERR_INVALID_PARAMETER_TYPE, name ? name : "null",

                   "integer");

        return;

    }



    *obj = qint_get_int(qobject_to_qint(qobj));

}
