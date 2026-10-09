/* 
 * Benchmark Sample ID : devign_8076
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9f62dde1303286b24ac8ce88be27e2b9b9c5f46
 */

static void qmp_output_push_obj(QmpOutputVisitor *qov, QObject *value)

{

    QStackEntry *e = g_malloc0(sizeof(*e));



    assert(qov->root);

    assert(value);

    e->value = value;

    if (qobject_type(e->value) == QTYPE_QLIST) {

        e->is_list_head = true;

    }

    QTAILQ_INSERT_HEAD(&qov->stack, e, node);

}
