/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_494
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a4a1c70dc759e5b81627e96564f344ab43ea86eb
 */

static GenericList *qobject_input_next_list(Visitor *v, GenericList *tail,

                                            size_t size)

{

    QObjectInputVisitor *qiv = to_qiv(v);

    StackObject *so = QSLIST_FIRST(&qiv->stack);



    if (!so->entry) {

        return NULL;

    }

    tail->next = g_malloc0(size);

    return tail->next;

}
