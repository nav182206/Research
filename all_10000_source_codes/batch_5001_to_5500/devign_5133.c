/* 
 * Benchmark Sample ID : devign_5133
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0426d53c6530606bf7641b83f2b755fe61c280ee
 */

static void qmp_input_get_next_type(Visitor *v, int *kind, const int *qobjects,

                                    const char *name, Error **errp)

{

    QmpInputVisitor *qiv = to_qiv(v);

    QObject *qobj = qmp_input_get_object(qiv, name, false);



    if (!qobj) {

        error_setg(errp, QERR_MISSING_PARAMETER, name ? name : "null");

        return;

    }

    *kind = qobjects[qobject_type(qobj)];

}
