/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7796
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=09e68369a88d7de0f988972bf28eec1b80cc47f9
 */

static void qmp_input_optional(Visitor *v, const char *name, bool *present)

{

    QmpInputVisitor *qiv = to_qiv(v);

    QObject *qobj = qmp_input_get_object(qiv, name, false, NULL);



    if (!qobj) {

        *present = false;

        return;

    }



    *present = true;

}
