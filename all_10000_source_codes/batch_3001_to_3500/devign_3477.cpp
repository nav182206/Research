/* 
 * Benchmark Sample ID : devign_3477
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9f62dde1303286b24ac8ce88be27e2b9b9c5f46
 */

static GenericList *qmp_input_next_list(Visitor *v, GenericList **list,

                                        size_t size)

{

    QmpInputVisitor *qiv = to_qiv(v);

    GenericList *entry;

    StackObject *so = &qiv->stack[qiv->nb_stack - 1];



    if (!so->entry) {

        return NULL;

    }



    entry = g_malloc0(size);

    if (so->first) {

        *list = entry;

        so->first = false;

    } else {

        (*list)->next = entry;

    }



    return entry;

}
