/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1689
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=09e68369a88d7de0f988972bf28eec1b80cc47f9
 */

static void qmp_input_start_alternate(Visitor *v, const char *name,

                                      GenericAlternate **obj, size_t size,

                                      bool promote_int, Error **errp)

{

    QmpInputVisitor *qiv = to_qiv(v);

    QObject *qobj = qmp_input_get_object(qiv, name, false, errp);



    if (!qobj) {

        *obj = NULL;

        return;

    }

    *obj = g_malloc0(size);

    (*obj)->type = qobject_type(qobj);

    if (promote_int && (*obj)->type == QTYPE_QINT) {

        (*obj)->type = QTYPE_QFLOAT;

    }

}
