/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2039
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=09e68369a88d7de0f988972bf28eec1b80cc47f9
 */

static void qmp_input_free(Visitor *v)

{

    QmpInputVisitor *qiv = to_qiv(v);

    while (!QSLIST_EMPTY(&qiv->stack)) {

        StackObject *tos = QSLIST_FIRST(&qiv->stack);



        QSLIST_REMOVE_HEAD(&qiv->stack, node);

        qmp_input_stack_object_free(tos);

    }



    qobject_decref(qiv->root);

    g_free(qiv);

}
